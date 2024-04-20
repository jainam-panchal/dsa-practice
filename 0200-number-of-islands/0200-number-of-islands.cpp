class Solution {
private:
    void bfs(vector<vector<char>> &grid, int i, int j) {
        
        if(grid[i][j] == '9' || grid[i][j] == '0') {
            return;
        }
        else if(grid[i][j] == '1') {
            // mark visited
            grid[i][j] = '9';

            if(i > 0) bfs(grid, i-1 , j);
            if(j > 0) bfs(grid, i , j-1);
            
            if(i<grid.size()-1) bfs(grid, i+1 , j);
            if(j<grid[0].size()-1) bfs(grid, i, j+1);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        // just bfs on each 1 and mark it visited
        
        int row = grid.size();
        int col = grid[0].size();
        
        int count= 0;
        for(int i=0 ; i<row ; i++) {
            for(int j=0 ; j<col ; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    bfs(grid, i , j);
                }
            }
        }
        
        return count;
    }
};