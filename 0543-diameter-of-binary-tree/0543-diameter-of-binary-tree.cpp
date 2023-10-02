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
    int height(TreeNode* root, int &maxi)
    {
        if(root == NULL)
            return 0;
        
        // find left height and right
        int leftH = height(root->left, maxi);
        int rightH = height(root->right, maxi);
        
        // update the maxi
        maxi = max(maxi , leftH + rightH);
        
        // count current maximum height
        return 1 + max(leftH, rightH);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxi = 0;
        height(root, maxi);
        return maxi;

    }
};