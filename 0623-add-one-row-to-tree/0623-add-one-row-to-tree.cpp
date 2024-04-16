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
    void dfs(TreeNode* root , int level, int &val , int &depth) {
        if(root == nullptr)
            return;
        
        // The Upper Node of the given depth and add new nodes
        if(level == depth-1) {
            TreeNode* newLeft = new TreeNode(val , root->left, nullptr);
            TreeNode* newRight = new TreeNode(val , nullptr , root->right);
            
            root->left = newLeft;
            root->right = newRight;
            
            return;

        } else {
            dfs(root->left, level+1 , val , depth);
            dfs(root->right, level+1, val, depth);
        }
        
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* ans;
        
        if(depth == 1) {
            ans = new TreeNode(val, root, nullptr);
            return ans;
        }
        
        dfs(root , 1 , val, depth);
        
        return root;
    }
};