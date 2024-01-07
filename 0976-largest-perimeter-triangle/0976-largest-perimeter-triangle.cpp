class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=nums.size()-3 ; i >= 0 ; --i) {
            int sum = nums[i] + nums[i+1];
            if(sum > nums[i+2])
                return sum + nums[i+2];
        }
        
        return 0;
    }
};