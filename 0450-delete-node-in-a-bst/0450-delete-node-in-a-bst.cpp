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
    TreeNode* deleteNode(TreeNode* root) {
        if(root->left == NULL) 
            return root->right;
        else if(root->right == NULL)
            return root->left;
        
        
        TreeNode* rightPart = root->right;
        TreeNode* leafRight = findLastRight(root->left);
        leafRight->right = rightPart;
        
        return root->left;
    }
    
    TreeNode* findLastRight(TreeNode* root) {
        if(root->right == NULL) 
            return root;
        
        return findLastRight(root->right);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) 
            return root;
        
        if(root->val == key) {
            return deleteNode(root);
        }

        TreeNode* temp = root;
        while(root != nullptr) {

            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) {
                    root->left = deleteNode(root->left);
                    break;
                }
                root = root->left;
            }
            else {
                if(root->right != NULL && root->right->val == key) {
                    root->right = deleteNode(root->right);
                    break;
                }
                root = root->right;
            }
        }

        return temp;
    }
};