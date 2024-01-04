class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i=0 ; i<nums.size() ; i++) {
            count[nums[i]]++;
        }
        
        int ans = 0;
        for(auto [value , currCount] : count) {
            if(currCount == 1) {
                return -1;
            }
            if(currCount % 3 == 0) {
                ans += currCount/3;
            }
            else {
                ans += (currCount/3) + 1;
            }
        }
        
        return ans;
    }
};