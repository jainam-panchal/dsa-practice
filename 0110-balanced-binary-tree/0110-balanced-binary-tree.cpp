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
    int check(TreeNode* node)
    {
        if(node == NULL) return 0;
        
        int leftH = check(node->left);
        if(leftH == -1) return -1;
        
        int rightH = check(node->right);
        if(rightH == -1) return -1;
        
        if(abs(leftH - rightH) > 1) return -1;
        else {
            return max(leftH, rightH) + 1;
        }
    }
    
public:
    bool isBalanced(TreeNode* root) 
    {
        return check(root) != -1;
    }
};