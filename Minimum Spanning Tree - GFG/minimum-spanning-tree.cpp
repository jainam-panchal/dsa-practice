//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // priority queue for the min heap - to get the lowest weight at the moment
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
        
        // to track if the element is visited or not
        vector<int> visited(V,0);
        
        //      weight ele
        // init {0  ,   0 } 
        pq.push({0,0});
        
        // to store ans
        int sum = 0;
        
        while(!pq.empty()) {
            
            // take out the top element
            auto node = pq.top();
            pq.pop();
            
            // extract
            int weight = node.first;
            int ele = node.second;
            
            // already visited, then skip
            if(visited[ele] == 1) continue;
            else {
                visited[ele] = 1;
                sum += weight;
                
                // add all it's adj
                for(auto it: adj[ele]) {
                    //first denotes the edge and second denotes the weight
                    int newEle = it[0];
                    int newWei = it[1];
                    
                    if(!visited[newEle])
                        pq.push({newWei, newEle});
                }
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends