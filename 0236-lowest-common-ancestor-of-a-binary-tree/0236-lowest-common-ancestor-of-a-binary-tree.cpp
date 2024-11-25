class Solution {
private:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& ans) {
        if (root == nullptr) return false;

        ans.push_back(root);

        if (root == target)
            return true;

        if (findPath(root->left, target, ans) || findPath(root->right, target, ans)) 
            return true;

        ans.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        
        TreeNode* lastMatched = nullptr;
        
        int i = 0, j = 0;
        while (i < pathP.size() && j < pathQ.size() && pathP[i] == pathQ[j]) {
            lastMatched = pathP[i];
            i++; 
            j++;
        }
        
        return lastMatched;
    }
};
