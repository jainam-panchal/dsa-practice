class Solution {
private:
    int binarySearch(vector<int>& nums,int start, int end, int k) {
        
        if(start > end) {
            return -1; 
        }
        
        if(start <= end) {
            
            // calc mid
            int mid = start + (end-start) / 2;
            
            // if key found
            if(nums[mid] == k) {
                return mid;
            }
            
            // move to the right side
            else if(nums[mid] < k) {
                return binarySearch(nums, mid+1, end, k);
            }
            
            // move to the left side
            else {
                return binarySearch(nums,start,mid-1, k);
            }
        }
        
        // if not found
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int ans = binarySearch(nums,0, nums.size()-1, target);
        return ans;
    }
};