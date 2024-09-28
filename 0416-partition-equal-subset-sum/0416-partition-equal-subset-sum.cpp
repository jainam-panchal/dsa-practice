class Solution {

private:
    bool helper(vector<int> &nums , int n , int sum, vector<vector<bool>> &dp) {
        for(int i=0 ; i <n+1 ; i++)
            dp[i][0] = true;
        
        for(int i=1 ; i<sum+1 ; i++)
            dp[0][i] = false;
        
        for(int i=1 ; i<n+1 ; i++) {
            for(int j=1 ; j<sum+1 ; j++) {
                if(nums[i - 1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        return dp[n][sum];
    }    
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 , n = nums.size();
        
        for(auto num : nums) sum += num;
        
        if(sum % 2 != 0) return false;
        
        sum /= 2;
        
        vector<vector<bool>> dp(n + 1 , vector<bool>(sum + 1));
        return helper(nums , n , sum , dp);
        
    }
};