class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size()-1;
        int ans = nums[0];
        
        while(start <= end) {
            
            int mid = (start + end) / 2;
            
            if(nums[start] <=  nums[mid]) {
                ans = min(ans, nums[start]);
                start = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                end = mid - 1;   
            }
        }
        
        return ans;
    }
};