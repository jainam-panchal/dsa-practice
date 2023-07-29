class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        bool flag = false;
        int current = 0;
        int ans = 0;
        
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] == 1) {
                if(flag != true)
                    flag = true;
                current++;
            }
            else {
                if(flag == true) {
                    flag = false;
                    ans = max(current,ans);
                    current = 0;
                }
            }
        }
        ans = max(current,ans);
        return ans;
    }
};