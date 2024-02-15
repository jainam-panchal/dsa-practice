class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long currSum = nums[0] + nums[1];
        long long ans = -1;
        
        for(int i=2 ; i<nums.size() ; i++) {
            // if it's smaller than my sum - yes!! 
            if(nums[i] < currSum)
                ans = currSum + nums[i];   
            currSum += nums[i];
        }
        
        return ans;
        
    }
};