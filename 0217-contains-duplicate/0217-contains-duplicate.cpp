class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int i=0 ; i<nums.size() ; i++) {
            if(hash[nums[i]] == 0)
                hash[nums[i]]++;
            else
                return true;
        }
        
        return false;
    }
};