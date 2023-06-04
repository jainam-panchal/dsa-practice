class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int curr = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[curr]){
                curr++;
            nums[curr] = nums[i];
            }
        }
        
        // Returning Number Of Unique Values
        return curr+1;
    }
};