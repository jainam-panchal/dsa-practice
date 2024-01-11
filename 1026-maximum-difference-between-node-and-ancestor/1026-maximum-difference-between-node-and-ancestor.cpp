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
    int dfs(TreeNode* root, int minVal ,int maxVal) {
        // we check the difference at the end
        if(root == NULL) {
            return maxVal - minVal;            
        }
        
        // update the min, max along the way
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        
        // for the subtrees
        int leftMax = dfs(root->left, minVal, maxVal);
        int rightMax = dfs(root->right, minVal, maxVal);
        
        return max(leftMax, rightMax);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};