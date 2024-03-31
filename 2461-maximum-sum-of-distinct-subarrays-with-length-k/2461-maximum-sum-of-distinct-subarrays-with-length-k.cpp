class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        long long maxi = 0;
        long long sum = 0;
        int n = nums.size();

        // setting up the window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }

        // if the size if equal then all elements are distinct
        if (mp.size() == k) {
            maxi = max(maxi, sum);
        }

        for (int j = k; j < n; j++) {
            sum += nums[j];
            mp[nums[j]]++;

            sum -= nums[j - k];
            mp[nums[j - k]]--;

            if (mp[nums[j - k]] <= 0) {
                mp.erase(nums[j - k]);
            }

            if (mp.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};