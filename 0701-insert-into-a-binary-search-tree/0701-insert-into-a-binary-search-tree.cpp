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
    void helper(TreeNode* root , int &val) {
        
        if(root->val < val) {
            if(root->right == nullptr) {
                root->right = new TreeNode(val);
                return;
            }
            helper(root->right , val);   
        }
        
        else {
            if(root->left == nullptr) {
                root->left = new TreeNode(val);
                return;
            }
            helper(root->left , val);
        }
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        helper(root , val);
        return root;
    }
};