class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = 0, ans = 0, streak = 0;
        
        for(auto num : nums) {
            if(num > maxEle) {
                maxEle = num;
                ans = 0 , streak = 0;
            }
            
            if(num == maxEle) streak++;
            else streak = 0;
            
            ans = max(ans , streak);
        }
        
        return ans;
    }
};