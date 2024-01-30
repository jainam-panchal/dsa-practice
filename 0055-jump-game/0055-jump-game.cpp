class Solution {
    bool solve(std::vector<int> &arr, int pos, int target, vector<int> &dp) {
        
        if (pos >= target - 1) {
            return true;
        }

        if (arr[pos] == 0) {
            return false;
        }
        
        if(dp[pos] != -1) {
            return dp[pos] == 1 ? true : false;
        }
        
        bool ans = false;
        for (int i = 1; i <= std::min(arr[pos], target - pos - 1); i++) {
            if (solve(arr, pos + i, target, dp)) {
                ans = true;
                break;
            }
        }
        
        dp[pos] = ans ? 1 : 0;
        return ans;
    }

public:
    bool canJump(std::vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, nums.size(), dp);
    }
};
