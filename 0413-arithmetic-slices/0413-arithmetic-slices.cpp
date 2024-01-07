class Solution {
private:
    int f(vector<int>& arr, int i, vector<int>& dp) {
        int ans = 0;
        for(int i=2 ; i<arr.size() ; i++) {
            if((arr[i] - arr[i-1]) == (arr[i-1] - arr[i-2]))
                dp[i] = dp[i-1] + 1;
            ans += dp[i];
        }
        return ans;
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int ans = f(nums, 0, dp);
        return ans;
    }
};