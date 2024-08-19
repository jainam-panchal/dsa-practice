class Solution {
private:
    int n;
    
    
    int helper(int len , int pasteLen , vector<vector<int>> &dp) {
        
        if(len == n) return 0;
        
        if(len > n) return 1000;
        
        if(dp[len][pasteLen] != -1) {
            return dp[len][pasteLen];
        }
        
        // copy and paste
        int ans1 = 2 + helper(len * 2 , len , dp);
        
        // paste
        int ans2 = 1 + helper(len + pasteLen , pasteLen, dp);
        
        
        return dp[len][pasteLen] = min(ans1 , ans2);
    }
    
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        this->n = n;
        
        vector<vector<int>> dp(1000 , vector<int>(1000 , -1));
        return 1 + helper(1, 1 , dp);
    }
};