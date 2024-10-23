class Solution {
private:
    int helper(int i , int j , int &m , int &n , vector<vector<int>> &grid , vector<vector<int>> &dp) {
        if(i < 0 || j < 0)
            return INT_MAX;
        
        if(i == 0 && j == 0) 
            return grid[0][0];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int subProb = grid[i][j] + min(helper(i-1 , j , m , n , grid , dp) ,
                                          helper(i , j-1 , m , n , grid , dp));
        
        return dp[i][j] = subProb;
        
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n , -1));
        
        return helper(m-1 , n-1 , m , n , grid , dp);
    }
};