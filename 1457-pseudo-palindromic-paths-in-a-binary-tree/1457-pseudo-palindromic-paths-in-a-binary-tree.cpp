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
    int result = 0;
    
    void solve(TreeNode* root, vector<int>& hash) {
        if(root == NULL) return;
        
        ++hash[root->val];
        
        if(root->right == NULL && root->left == NULL) {
            // check for the odd occ
            int count=0;
            for(int i=0 ; i<hash.size() ; i++) {
                if(hash[i] % 2 != 0)
                    count++;
            }
            
            if(count <= 1)
                result += 1; 
        }
        
        solve(root->left, hash);
        solve(root->right, hash);        
        
        --hash[root->val];
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10, 0);
        
        solve(root, hash);
        return result;
    }
};