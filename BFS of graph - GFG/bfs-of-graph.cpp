//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        // start with init config
        int visited[V] = {0};
        visited[0] = 1;
        
        vector<int> ans;
        queue<int> q;
        q.push(0);
        
        
        while(!q.empty())
        {
            // get the first element
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // traverse all adj nodes of current node
            for(auto it: adj[node])
            {
                // only if it's not visited, push it
                if(!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends