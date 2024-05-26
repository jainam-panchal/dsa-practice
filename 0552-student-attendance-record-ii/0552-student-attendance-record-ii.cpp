class Solution {
private:
    int dp[100001][2][3];
    
    const int M = 1e9 + 7;
    
    int helper(int n, int abs, int late) {
        if (abs >= 2 || late >= 3) {
            return 0;
        }
        
        if (n == 0) {
            return 1;
        }
        
        if(dp[n][abs][late] != -1) {
            return dp[n][abs][late];
        }
        
        int P = helper(n - 1, abs, 0) % M;
        int L = helper(n - 1, abs, late + 1) % M;
        int A = helper(n - 1, abs + 1, 0) % M;
        
        return dp[n][abs][late] = ((A + L) % M + P) % M;
    }
    
public:
    int checkRecord(int n) {
        memset(dp, -1 , sizeof(dp));
        return helper(n, 0, 0);
    }
};
