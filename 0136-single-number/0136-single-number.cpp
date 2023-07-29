class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return nums[0];
        }
            
        unordered_map<int, int> map;
        
        for(int i=0 ; i<nums.size() ; i++){
            map[nums[i]]++;
        }
        
        for(auto i : map) {
            if(i.second == 1) {
                return i.first;
            }
        }
        
        return nums[0];
    }
};