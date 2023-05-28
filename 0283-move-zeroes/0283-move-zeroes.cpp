class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      
        // Two Pointer Approach
        int i = 0;
        for(int j=0 ; j<nums.size() ; j++){
            if(nums[j] != 0) {
                swap(nums[i],nums[j]);
                i++;
            }
        }
        
    }
};