class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n , vector<int>(n, INT_MAX));
        
        // Fill the first row of dp with matrix values
        for(int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=1; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                
                int minSum = INT_MAX;
                for(int k=0 ; k<n ; k++) {
                    // excluding 
                    if(k != j) {
                        minSum = min(dp[i-1][k] , minSum); 
                    }
                }
                dp[i][j] = matrix[i][j] + minSum;
            
            }
        }
        
        int ans = INT_MAX;
        for(int i=0 ; i<n ; i++) {
            ans = min(ans , dp[n-1][i]);
        }
        
        return ans;
    }
};
