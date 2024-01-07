class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 3)
            return true;
        
        int which = 0; // 0 represents "not determined yet"
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                if(which == 0)
                    which = 1; // increasing
                else if(which == -1)
                    return false; // array is not monotonic
            } else if(nums[i] < nums[i-1]) {
                if(which == 0)
                    which = -1; // decreasing
                else if(which == 1)
                    return false; // array is not monotonic
            }
        }
        
        return true;
    }
};