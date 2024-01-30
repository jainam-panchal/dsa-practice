class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        
        int left = 2;
        int right = 2;
        
        while(right < nums.size()) {
            
            if(nums[left - 2] != nums[right]) {
                // the right position
                nums[left] = nums[right];
                left++;
                right++;
            }
            else {
                // find the right position
                right++;
            }
            
        }
        
        return left;
    }
};