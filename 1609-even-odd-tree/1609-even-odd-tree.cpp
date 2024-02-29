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
    bool solve(TreeNode* root) {
        if (!root)
            return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool evenLevel = true;
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp(n);
            
            for(int i=0 ; i<n ; i++) {
                TreeNode* ele = q.front(); q.pop();
                temp[i] = ele->val;
                
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
            // cout << n << endl;
            
            if (evenLevel) {
                for (int i = 0; i < n; i++) {
                    // Check if values are odd and strictly increasing
                    if (temp[i] % 2 == 0 || (i > 0 && temp[i] <= temp[i - 1])) {
                        return false;
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    // Check if values are even and strictly decreasing
                    if (temp[i] % 2 != 0 || (i > 0 && temp[i] >= temp[i - 1])) {
                        return false;
                    }
                }
            }

            evenLevel = !evenLevel;
        }
        
        return true;
    }
    
public:
    bool isEvenOddTree(TreeNode* root) {
        return solve(root);
    }
};