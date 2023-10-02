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
    int maxSum(TreeNode* node, int &maxi)
    {
        // base
        if(node == NULL)
            return 0;
        
        // recursion
        // do not consider negatives
        int leftM = max(0, maxSum(node->left, maxi));
        int rightM = max(0, maxSum(node->right, maxi));
        
        // update maxi
        maxi = max(maxi, leftM + rightM + node->val);
        
        // cal
        return node->val + max(leftM, rightM);
        
    }
    
public:
    int maxPathSum(TreeNode* root) 
    {
        int maxi = INT_MIN;
        maxSum(root, maxi);
        return maxi;
    }
};