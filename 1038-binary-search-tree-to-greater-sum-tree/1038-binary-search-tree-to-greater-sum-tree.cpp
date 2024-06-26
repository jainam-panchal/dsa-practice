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
    void solve(TreeNode* root , int &sum) {
        if(!root->left && !root->right) {
            root->val += sum;
            sum = root->val;
            return;
        }
        
        if(root->right) 
            solve(root->right, sum);
        
        int newValue = root->val + sum;
        sum = newValue;
        root->val = newValue;
        
        if(root->left)
            solve(root->left , sum);
        
        return;
    }
    
   
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == nullptr) {
            return root;
        }
        
        int sum = 0;
        solve(root , sum);
        return root;
    }
};