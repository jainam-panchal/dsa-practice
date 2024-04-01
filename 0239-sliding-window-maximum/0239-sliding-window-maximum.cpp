class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // monotonic -> increasing to decreasing
        deque<int> dec;
        vector<int> ans;
        
        int i=0, j=0;
        while(j < n) {
            
            if(dec.empty() || nums[dec.back()] <= nums[j]) {
                
                //  remove all smaaller elements smaller than nums[j] from back
                while(!dec.empty() && nums[dec.back()] < nums[j]) {
                    dec.pop_back();
                }
                
                dec.push_back(j);
            } else {
                
                // if our maxi is out of range
                while(!dec.empty() && dec.front() <= j-k) {
                    dec.pop_front();
                }
                dec.push_back(j);
            }
            
            
            if(j - i + 1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                ans.push_back(nums[dec.front()]);
                
                if(i == dec.front()) {
                    dec.pop_front();
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
        
    }
};