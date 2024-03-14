class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        unordered_map<int, int> map;
        
        map[0] = 1;
        int result = 0;
        int currSum = 0;
        
        for(auto &val : nums) {
            currSum += val;
            
            int remSum = currSum - goal;
            if(map.find(remSum) != map.end()) {
                result += map[remSum];
                
            }
            map[currSum]++;
        }
        
        return result;
    }
};