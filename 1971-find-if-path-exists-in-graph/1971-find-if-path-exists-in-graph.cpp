class Solution {
private:
    bool checkDFS(unordered_map<int, vector<int>> &mp , int s, int d, vector<int> &visited) {
        
        // best case - found the path
        if(s == d) return true;
        
        // mark visited
        visited[s] = 1;
        
        // call dfs on every node
        for(auto i : mp[s]) {
            if(!visited[i] && checkDFS(mp , i, d, visited) == true)
                return true;
        }
        
        return false;
    }
    
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
        return checkDFS(mp, source, destination, visited);
    }
};