/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        if(root == nullptr) return root;

        // Step 1 : Find LevelSum
        vector<int> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int currSum = 0;
            int n = q.size();

            while(n) {
                TreeNode* temp = q.front(); q.pop();
                currSum += temp->val;
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                n--;
            }

            levelSum.push_back(currSum);
        }

        // Step 2 : Update each nodes
        q.push(root);
        root->val = 0; // always

        int level = 1;

        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                TreeNode* temp = q.front(); q.pop();

                int siblingSum = temp->left != nullptr ? temp->left->val : 0;
                siblingSum += temp->right != nullptr ? temp->right->val : 0;

                if(temp->left) {
                    temp->left->val = levelSum[level] - siblingSum;
                    q.push(temp->left);
                }
                if(temp->right) {
                    temp->right->val = levelSum[level] - siblingSum;
                    q.push(temp->right);
                }
            }
            level++;
        }

        return root;

    }
};