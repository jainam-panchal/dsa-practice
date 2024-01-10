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
    
    int amountOfTime(TreeNode* root, int start) {
        makeGraph(root);
        
        queue<int> q;
        q.push(start);
        
        unordered_set<int> visited;
        
        int minPassed = -1;
        
        while(!q.empty()) {
            minPassed++;
            int n = q.size();
            
            for(int lvlSize = q.size() ; lvlSize > 0 ; --lvlSize) {
                int currNode = q.front();
                q.pop();
                visited.insert(currNode);
                
                for(int adjNode : graph[currNode]) {
                    if(!visited.count(adjNode)) {
                        q.push(adjNode);
                    }
                }
            }
        }
        
        return minPassed;
    }
    
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
};