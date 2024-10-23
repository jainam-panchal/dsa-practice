class Solution {
    int helper(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp) {
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int left = helper(triangle, i + 1, j, dp);
        int right = helper(triangle, i + 1, j + 1, dp);
        
        return dp[i][j] = triangle[i][j] + min(left, right);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0; // Handle the case where the triangle is empty
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return helper(triangle, 0, 0, dp);
    }
};
