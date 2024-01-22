class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {        
        
        // using in-place array as hashmap
        int duplicate = 0;
        int miss = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            
            int index = abs(nums[i]) - 1;
            
            // if it's already negative
            if(nums[index] < 0)
                duplicate = abs(nums[i]);
            
            // make that pos negative
            nums[index] = -nums[index];
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && (i + 1) != duplicate) {
                miss = i + 1;
                return {duplicate, miss};
            }
        }
        
        return {duplicate, miss};
    }
};
