class Solution {
private:
    int helper(int i , int j , int &m , int &n , vector<vector<int>> &grid , vector<vector<int>> &dp) {

        if(i < 0 || j < 0) return 0;

        if(grid[i][j] == 1) return 0;

        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) 
            return dp[i][j];

        dp[i][j] = helper(i-1 , j , m , n , grid , dp) + helper(i , j-1 , m , n , grid , dp);

        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0;

        return helper(m-1 , n-1 , m , n , obstacleGrid , dp);
    }
};