class Solution {
    int helper(vector<vector<int>> &dp , int i , int j , int m , int n) {
        if(i == m-1 && j == n-1)
            return 1;
        
        if(i >= m || i < 0 || j >= n || j < 0)
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        vector<vector<int>> directions = {{0 , 1} , {1 , 0}};
        int totalWays = 0;
        
        for(auto const &dir : directions) {
            totalWays += helper(dp , i+dir[0] , j+dir[1], m, n);
        }
        
        return dp[i][j] = totalWays;
        
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return helper(dp , 0 , 0 , m , n);
    }
};