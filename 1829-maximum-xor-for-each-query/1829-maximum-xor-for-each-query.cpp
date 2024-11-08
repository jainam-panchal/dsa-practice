class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        
        
        int xr = 0;
        for(int i=0 ; i<n ; i++) {
            xr = xr ^ nums[i];
        }
        
        vector<int> ans;
        int mask = (1 << maximumBit) - 1;

        for(int i=0 ; i<nums.size() ; i++) {
            int k = mask ^ xr;
            ans.push_back(k);
            
            xr = xr ^ nums[n-i-1];
        }
        
        return ans;
    }
};