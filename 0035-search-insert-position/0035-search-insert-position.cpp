class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size()-1;
        int start = 0;
        int end = n;
        
        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            
            // found element is larger, discard right part
            else if(nums[mid] > target) {
                end = mid - 1;
            }
            
            // found element is smaller, discard left part
            else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};