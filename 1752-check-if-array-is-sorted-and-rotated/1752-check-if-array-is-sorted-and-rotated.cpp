class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count = 0;
        int n = nums.size();

        for(int i=1 ; i<n ; i++) {
            if(nums[i-1] > nums[i]) {
                count++;
            }
        }

        if(nums[n-1] > nums[0]) {
            count++;
        }

        // 0 should be included if array is [1,1,1]
        return count<=1;
    }
};