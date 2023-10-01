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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector <int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            // to make a level list
            vector<int> level;

            // how many elements which have to add left and right element
            int size = q.size();

            // adding left and right elements to queue
            for(int i=0 ; i<size ; i++)
            {
                // get the first element
                TreeNode* element = q.front();
                q.pop();

                if(element->left != NULL) q.push(element->left);
                if(element->right != NULL) q.push(element->right);

                // add the element value to current level
                level.push_back(element->val);
            }

            // add whole list to the ans
            ans.push_back(level);
        }

        return ans;
    }
};