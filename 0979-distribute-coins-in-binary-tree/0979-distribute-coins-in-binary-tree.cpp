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
    int helper(TreeNode* root , int &totalSum) {
        if(root == nullptr) return 0;
        
        int left = helper(root->left , totalSum);
        int right = helper(root->right, totalSum);
        
        int curr = root->val + left + right - 1;
        totalSum += abs(curr);
        
        return curr;
    }    

public:
    int distributeCoins(TreeNode* root) {
        int totalSum = 0;
        helper(root , totalSum);
        
        return totalSum;
    }
};