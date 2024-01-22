class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {        
        int N = nums.size();
        
        long long x = 0;  // duplicate - missing 
        long long y = 0;  // duplicate^2 - missing^2
        
        for(int i=1 ; i<=N ; i++) {
            x += nums[i-1] - i;
            y += pow(nums[i - 1], 2) - pow(i, 2);
        }
        
        int missing = (y - pow(x,2)) / (2 * x);
        int duplicate = missing + x;
    
        return {duplicate, missing};
    }
};
