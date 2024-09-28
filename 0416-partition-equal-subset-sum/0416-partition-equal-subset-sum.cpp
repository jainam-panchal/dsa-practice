class Solution {

private:
    bool helper(vector<int> &nums , int n , int sum, vector<vector<int>> &dp) {
        if(sum == 0) return true;
        
        if(n <= 0) return false;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(nums[n-1] > sum)
            return dp[n][sum] = helper(nums , n-1 , sum, dp);
        
        return dp[n][sum] = helper(nums , n-1 , sum, dp) || helper(nums , n-1 , sum - nums[n - 1], dp);
    }    
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 , n = nums.size();
        
        for(auto num : nums) sum += num;
        
        if(sum % 2 != 0) return false;
        
        sum /= 2;
        
        vector<vector<int>> dp(n + 1 , vector<int>(sum + 1, -1));
        return helper(nums , n , sum , dp);
        
    }
};