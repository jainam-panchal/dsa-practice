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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        // st1 to traverse and st2 to store sequence
        stack<TreeNode*> st1, st2;
        st1.push(root);
        
        while(!st1.empty())
        {   
            // update root
            root = st1.top();
            st1.pop();
            // add it to the considered stack
            st2.push(root);
            
            // insert left and right
            if(root->left != NULL) st1.push(root->left );
            if(root->right != NULL) st1.push(root->right );
        }
        
        
        // get all elements
        while(!st2.empty())
        {
            auto ele = st2.top();
            ans.push_back(ele->val);
            st2.pop();
        }
        return ans;
    }
};