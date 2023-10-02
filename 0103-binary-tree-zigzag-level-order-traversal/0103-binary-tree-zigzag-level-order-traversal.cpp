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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        bool flag = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0 ; i<size ; i++)
            {
                TreeNode* element = q.front();
                q.pop();
                
                int index = flag ? (size - i - 1) : i ;
                level[index] = element->val;
                
                if(element->left) q.push(element->left);
                if(element->right) q.push(element->right);
                    
            }
            
            ans.push_back(level);
            flag = !flag;
        }
        
        return ans;
    }
};