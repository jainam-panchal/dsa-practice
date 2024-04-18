class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        // for every row
        for(int i=0 ; i<grid.size() ; i++) {
            // for every col
            for(int j=0 ; j<grid[i].size() ; j++) {
                if(grid[i][j] == 1) {
                    perimeter += 4;
                    // up
                    if(i-1 >= 0 && grid[i-1][j] == 1)
                        perimeter--;
                    // down
                    if(i+1 < grid.size() && grid[i+1][j] == 1)
                        perimeter--;
                    // right
                    if(j+1 < grid[i].size() && grid[i][j+1] == 1)
                        perimeter--;
                    // left
                    if(j-1 >= 0 && grid[i][j-1] == 1)
                        perimeter--;
                }
                
            }
        }
        
        return perimeter;
    }
};