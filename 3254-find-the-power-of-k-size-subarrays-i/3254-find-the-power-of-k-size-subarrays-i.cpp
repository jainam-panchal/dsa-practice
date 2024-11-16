class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), count = 1;
        vector<int> arr(n - k + 1, -1);
        
        for (int i = 1; i < k; i++) {
            if (nums[i - 1] + 1 == nums[i])
                count++;
            else
                count = 1;
        }
        
        if (count == k) 
            arr[0] = nums[k - 1];
        
        for (int j = k; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1)
                count++;
            else
                count = 1;
            
            if (count >= k) 
                arr[j - k + 1] = nums[j];
        }
        
        return arr;
    }
};
