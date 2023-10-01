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
    int findHeight(TreeNode* root)
    {
        if(root == NULL) 
            return 0;
        
        return 1 + max(findHeight(root->left) , findHeight(root->right));
    }
    
    
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return true;
        
        int leftH = findHeight(root->left);
        int rightH = findHeight(root->right);
        
        // balanced tree = (leftDepth - rightDepth) <= 1
        int def = abs(leftH - rightH);

        // check current node and then move forward to check left, right
        if(def <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        else 
            return false;
        
    }
};