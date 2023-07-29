class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // edge case
        if(nums.size() == 1) {
            return nums[0];
        }
            
        // unordered map to store all occurence
        unordered_map<int, int> map;
        for(int i=0 ; i<nums.size() ; i++){
            map[nums[i]]++;
        }
        
        // finding element with 1 occurance
        for(auto i : map) {
            if(i.second == 1) {
                return i.first;
            }
        }
        
        // doesn't matter what it is
        return -1;
    }
};