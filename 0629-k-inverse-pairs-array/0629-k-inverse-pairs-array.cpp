class Solution {
public:
    int MOD = 1e9+7;
    
    int kInversePairs(int n, int k) {
        
        // O(n * k * k) - BRUTEEFORCEEE
        
        int DP[1001][1001] = {1};  
        
        // we only care about the order, not the range
        for (int i = 1; i <= n; i++) {
            
            // pick the first 
            for (int j = 0; j <= k; j++) {
                
                // pick the second
                for (int x = 0; x <= min(j, i - 1); x++) {
                    
                    if (j - x >= 0) {
                        DP[i][j] = (DP[i][j] + DP[i - 1][j - x]) % MOD;
                    }
                }
            }
        }

        return DP[n][k];
        
    }
};