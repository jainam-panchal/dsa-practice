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
    void dfs(TreeNode* root , string temp , string &ans) {
        if(!root) return;
        
        temp = char(root->val + 'a') + temp;
        
        // if it's left node
        if(!root->left && !root->right) {
            
            // only update on leaf node
            if(ans == "" || temp < ans) {
                ans = temp;
            }
            
            return;
        }
        
        dfs(root->left , temp , ans);
        dfs(root->right , temp , ans);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string ans , temp;
        dfs(root , temp , ans);
        
        return ans;
    }
};