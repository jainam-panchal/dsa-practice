class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> costs(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj; // [src] <dest , price>
        
        // Creating Adjustancy List
        for(auto flight : flights) {       
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
                
            adj[from].push_back({to, price});                            
        }
        
        queue<pair<int, int>> q;// destination and cost
        q.push({src, 0});
        
        int step = 0;
        
        while(!q.empty() && step <= k){
            int queSize = q.size();
            // Level Wise
            for(int i=0 ; i<queSize ; i++) {
                int u = q.front().first;
                int c = q.front().second;     
                q.pop();
                
                // process it's every node
                for(auto it : adj[u]) {
                    int v = it.first;
                    int cc = it.second;
                    
                    if(c + cc < costs[v]) {
                        costs[v] = c + cc;
                        q.push({v, c+cc});
                    }
                }
            }
            
            step++;
        }
        
        if(costs[dst] == INT_MAX) {
                return -1;
        }

        return costs[dst];
    }
};