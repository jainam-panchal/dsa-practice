class Solution {
public:
    int m;
    int n;
    int dp[71][71][71];
    
    int solve(vector<vector<int>> &grid, int row, int c1, int c2) {
        
        // base condition
        if(row >= m) {
            return 0;
        }
        
        if(dp[row][c1][c2] != -1) {
            return dp[row][c1][c2];
        }
        
        int cherry = grid[row][c1];
        if(c1 != c2) {
            cherry += grid[row][c2];
        }
        
        
        int ans = 0;
        for(int i=-1 ; i<= 1 ; i++) { //R1
            for(int j=-1; j<= 1 ; j++) { //R2
                int newrow = row + 1;
                int newc1 = c1 + i;
                int newc2 = c2 + j;
                
                if(newc1 >= 0 && newc1 < n && newc2 >= 0 && newc2 < n)  
                    ans = max(ans, solve(grid, newrow , newc1, newc2));   
            }
        }
        
        return dp[row][c1][c2] = cherry + ans;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(grid, 0 , 0 , n-1);
    }
};