class Solution {
private:
    bool checkBFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2 , int i , int j) {
        
        // out of bound
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
            return true;
        }
       
        // we only care about land
        if(grid2[i][j] != 1) {
            return true; // just finish exploring
        }
        
        // mark visited
        grid2[i][j] = -1;
        
        // grid1 must have one
        bool result = (grid1[i][j] == 1);
        
        result = result & checkBFS(grid1 , grid2 , i + 1 , j);
        result = result & checkBFS(grid1 , grid2 , i - 1 , j);
        result = result & checkBFS(grid1 , grid2 , i , j + 1);
        result = result & checkBFS(grid1 , grid2 , i , j - 1);
        
        return result;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int count = 0;
        int n = grid2.size() , m = grid2[0].size();
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                // found an island
                if(grid2[i][j] == 1 && checkBFS(grid1 , grid2 , i , j)) {
                    count++;
                }
                
            }
        }
        
        
        return count;
    }
};