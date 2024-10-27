class Solution {
private:
    long long helper(vector<int>& arr, int sum, int n, vector<vector<long long>>& dp) {
        if (sum == 0 && n == 0) return 1;
        if (n == 0) return 0;
        if (dp[n][sum] != -1) return dp[n][sum];

        long long taken = 0, notTaken = 0;

        if (arr[n - 1] <= sum) {
            taken = helper(arr, sum - arr[n - 1], n - 1, dp);
        }

        notTaken = helper(arr, sum, n - 1, dp);

        return dp[n][sum] = taken + notTaken;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) sum += i;

        if (sum - target < 0 || (sum - target) % 2) return 0;

        int targetSum = (sum - target) / 2;
        vector<vector<long long>> dp(n + 1, vector<long long>(targetSum + 1, -1));
        return helper(nums, targetSum, n, dp);
    }
};