class Solution {

private:
    void DfsTraverseThis(vector<vector<int>>& mt,int u, vector<bool>& visited) {
        // mark this visited
        visited[u] = true;
        
        // dfs on it's all adj
        for(int i=0 ; i<mt[u].size() ; i++) {
            if(!visited[i] && mt[u][i] == 1)
                DfsTraverseThis(mt, i, visited);
        }
    }
    
    void BfsTraverseThis(vector<vector<int>>& mt,int u, vector<bool>& visited) {
        // mark this visited
        visited[u] = true;
        
        queue<int> q;
        q.push(u);
        
        while(!q.empty()) {
            // get front element and mark it visited
            int x = q.front(); q.pop();
            visited[x] = 1;
            
            for(int i=0 ; i<mt[x].size() ; i++) {
                if(!visited[i] && mt[x][i] == 1){
                    q.push(i);
                }
            }
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
                // DfsTraverseThis(isConnected, i, visited);
                BfsTraverseThis(isConnected, i, visited);
            }
        }
        
        return count;
    }
};