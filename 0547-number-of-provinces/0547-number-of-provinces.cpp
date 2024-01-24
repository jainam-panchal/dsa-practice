class Solution {

private:
    // simple dfs
    void DfsTraverseThis(vector<vector<int>>& mt,int u, vector<bool>& visited) {
        // mark this visited
        visited[u] = true;
        
        // dfs on it's all adj
        for(int i=0 ; i<mt[u].size() ; i++) {
            if(mt[u][i] == 1 && !visited[i])
                DfsTraverseThis(mt, i, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
            
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                count++;
                DfsTraverseThis(isConnected,i, visited);
            }
        }
        
        return count;
    }
};