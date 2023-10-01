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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        // declare the ans vector
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true) {
            if(node != NULL)
            {
                // add it to the stack
                st.push(node);
                // move to the left 
                node = node->left;
            }
            else {
                
                // no element to consider
                if(st.empty() == true) break;                
                
                // now add root element
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                
                // move to the right part
                node = node->right;
            }
        }
        
        return ans;
    }
};