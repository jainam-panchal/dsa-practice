class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        int i=0;
        int j=0;
        
        int result = 0;
        
        while(j < nums.size()) {
            map[nums[j]]++;
            
            while(i<j && map[nums[j]] > k) {
                map[nums[i]]--;
                i++;
            }
            
            result = max(result , j-i+1);
            j++;
        }
        
        return result;
    }
};