class Solution {
public:
    typedef pair<double , int> P;  // prob and node
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        // start to end , undirected graph -> DIJKSTRA'S ALGO (e-logv)
        
        priority_queue<P> pq; // by default it's max heap
        vector<double> result(n , 0); 
        
        result[start_node] = 1;
        pq.push({1.0 , start_node} );
        
        unordered_map<int, vector<pair<int,double>>> adj;
        for(int i=0 ; i<edges.size() ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];
            adj[u].push_back({v , prob});
            adj[v].push_back({u , prob});
        }
        
        while(!pq.empty()) {
            
            int currNode = pq.top().second;
            double currProb = pq.top().first; 
            pq.pop();
            
            for(auto &temp : adj[currNode]) {
                double adjProb = temp.second;
                int adjNode = temp.first;
                
                if(result[adjNode] < currProb * adjProb) {
                    result[adjNode] = currProb * adjProb;
                    pq.push({result[adjNode] , adjNode});
                }
            }
        }
        
        return result[end_node];
        
        
    }
};