class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, corrections = 0;
        int ans = 0;
        
        for(int i=0 ; i<nums.size() ; i++) {
                if(nums[i] == 0) corrections++;
                
                if(corrections > k) {
                    if(nums[start] == 0) corrections--;
                    start++;
                }
                else {
                    ans = max(ans,i-start+1);
                }
        }
        
        return ans;
    }
}; 