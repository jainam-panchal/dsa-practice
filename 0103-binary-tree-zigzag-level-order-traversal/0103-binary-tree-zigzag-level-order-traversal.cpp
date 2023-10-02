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
        
        // for the zigzag pattern
        bool pattern = false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            
            // for all elements in q right now
            for(int i=0 ; i<size ; i++)
            {   
                
                // get the first element
                TreeNode* element = q.front();
                q.pop();
                
                // explore their left and right and add it to queue
                if(element->left != NULL) q.push(element->left);
                if(element->right != NULL) q.push(element->right);
                
                // in zigzag way, we need to insert at begining
                if(pattern)
                    level.insert(level.begin(),element->val);
                // just normal level wise
                else 
                    level.push_back(element->val);
            }
            
            // flip the pattern
            pattern = !pattern;
            
            // add the vector to ans
            ans.push_back(level);
        }
        
        return ans;
    }
};