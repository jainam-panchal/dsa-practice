class Solution {
private:
    int helper(int ind , int amount , vector<int>& coins, vector<vector<int>> &dp) {
        
        if(ind == 0) {
            if(amount % coins[ind] == 0) return amount / coins[ind];
            else return 1e9;
        }
        
        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        int notTaken = helper(ind - 1 , amount , coins , dp);
        int taken = 1e9;
        
        if(amount >= coins[ind]) {
            taken = 1 + helper(ind , amount - coins[ind] , coins , dp);
        }
        
        return dp[ind][amount] = min(notTaken , taken);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1 , -1));
        int ans = helper(n-1 , amount , coins , dp);
        if(ans >= 1e9) return -1;
        
        return ans;
    }
};