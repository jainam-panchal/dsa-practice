class Solution {
    int Recursion(int i, vector<int> &nums, vector<int> &dp)
    {
        
        if (i == 0)
            return nums[i];
        if (i < 0)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int pick = nums[i] + Recursion(i - 2, nums, dp);
        int nonPick = 0 + Recursion(i - 1, nums, dp);
        
        dp[i] = max(pick, nonPick);
        
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        int ans;
        vector<int> dp (nums.size(), -1);
        ans = Recursion(nums.size()-1, nums, dp);
        return ans;
    }
};