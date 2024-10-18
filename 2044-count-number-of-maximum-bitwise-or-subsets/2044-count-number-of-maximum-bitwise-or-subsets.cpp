class Solution {
private:
    int helper(vector<int> &nums , int i , int curr , int target) {
        if(i >= nums.size()) {
            return curr == target;
        }
        
        int without = helper(nums , i+1 , curr  , target);
        int with = helper(nums , i+1 , curr | nums[i] , target);
        
        
        return without + with;
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxorval = 0;
        
        for(auto num : nums) maxorval |= num;
        
        return helper(nums , 0 , 0 , maxorval);
        
        
    }
};