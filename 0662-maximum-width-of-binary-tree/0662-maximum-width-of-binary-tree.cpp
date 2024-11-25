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
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int width = 0;
        
        // pair<node , assinged number>
        queue<pair<TreeNode* , unsigned long long>> q;
        q.push({root , 1});
        
        while(!q.empty()) {
            int size = q.size();
            
            unsigned long long leftMost = q.front().second;
            unsigned long long rightMost = q.back().second;
            
            width = max(width , (int)(rightMost - leftMost + 1));
            
            for(int i=0 ; i<size ; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                if(node->left) q.push({node->left , index*2});
                if(node->right) q.push({node->right , index*2 + 1});
            }
        }
        
        
        return width;
    }
};