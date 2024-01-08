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
    void inorderF(TreeNode* root, int low , int end, int& ans) {
        if(root == nullptr)    
            return;
        
        inorderF(root->left , low , end , ans);
        if((root->val >= low) && (root->val <= end))
            ans += root->val;
        inorderF(root->right, low , end , ans);
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        int ans = 0;
        inorderF(root, low , high, ans);
        
        return ans;
    }
};