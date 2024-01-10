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
    unordered_map<int, vector<int>> graph;

    void makeGraph(TreeNode* root) {
        if(root == NULL) return;
            
        if(root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        
        if(root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        
        makeGraph(root->left);
        makeGraph(root->right);
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        
        makeGraph(root);
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        
        int minTime = -1;
        
        while(!q.empty()) {
            minTime++;
            
            for(int i=q.size(); i > 0  ; i--) {
                int currNode = q.front();
                q.pop();
                visited.insert(currNode);
                
                for(int adj : graph[currNode]) {
                    if(!visited.count(adj)) {
                        q.push(adj);
                    }
                }
            }
        }
        
        return minTime;
            
    }
};