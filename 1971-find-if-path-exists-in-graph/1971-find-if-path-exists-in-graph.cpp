class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // creating bi directional adj list
        unordered_map<int, vector<int>> mp;
        for(auto i : edges) {
            int s = i[0];
            int d = i[1];
            
            mp[s].push_back(d);
            mp[d].push_back(s);
        }
        
        vector<int> visited(n , 0);
        
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        
        while(!q.empty()) {
            int s = q.front(); q.pop();
            if(s == destination) 
                return true;
            
            for(auto i : mp[s]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        
        return false;
    }
};