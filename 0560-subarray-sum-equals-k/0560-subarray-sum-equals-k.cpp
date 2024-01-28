class Solution {
public:
    int subarraySum(vector<int>& nums, int key) {
        
        // Bruteforce approach - Go through every single subarray and find the sum
        
        // Optimal using commulative sum 
        int result = 0;
        
        // calc commulative sum array
        vector<int> cm(nums.size());
        cm[0] = nums[0];
        for(int i=1 ; i<nums.size() ; i++) {
            cm[i] = cm[i-1] + nums[i];
        }
        
        // go though every single commulative sum
        // x[i] = val then if (key - val) is present in the mp?
        unordered_map<int,int> mp;
        mp.insert({0,1});
        
        for(int i=0 ; i<nums.size() ; i++) {
            
            int diff = cm[i] - key;
            if(mp.count(diff)) {
                result += mp[diff];
            }
            mp[cm[i]]++;
        }
        
        return result;
        
    }
};