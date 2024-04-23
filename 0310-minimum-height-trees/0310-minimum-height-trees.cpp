class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};
        
        vector<int> degree(n, 0);
        unordered_map<int , vector<int>> adj;
        for(auto edge : edges) {
            int first = edge[0];
            int second = edge[1];
            
            degree[first]++; degree[second]++;
            
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        
        // add leaf nodes into the queue
        queue<int> q;
        for(int i=0 ; i<n ; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
        
        int totalNodes = n;
        
        while(totalNodes > 2) {
            int size = q.size();
            
            totalNodes -= size;
            
            for(int i=0 ; i<size ; i++) {
                int node = q.front(); q.pop();
                
                for(auto connected : adj[node]) {
                    degree[connected]--;
                    if(degree[connected] == 1) {
                        q.push(connected);
                    }
                }
            }
        }
        
        // only two possible ans : 1,2
        vector<int> result;
        while(!q.empty()) {
            result.push_back(q.front()); q.pop();
        }
        
        return result;
    }
};