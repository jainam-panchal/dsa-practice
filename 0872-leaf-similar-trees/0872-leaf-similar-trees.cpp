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
private:
    void findLeaf(TreeNode* root , vector<int>& arr) {
        
        if(!root) {
            return;
        }
        
        if(!root->left && !root->right) {
            arr.push_back(root->val);
            return;
        }
        findLeaf(root->left, arr);
        findLeaf(root->right, arr);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        findLeaf(root1, r1);
        findLeaf(root2, r2);
        
        return r1 == r2;

    }
};