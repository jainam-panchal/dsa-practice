class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {        
        
        // using in-place array as hashmap
        // mapping 1 to n -> 0 to n-1
        
        int dup = 0;
        
        for(int i=0 ; i<nums.size() ; i++) {
            int index = abs(nums[i]) - 1;
            
            if(nums[index] < 0) {
                dup = index + 1;
            }
            
            nums[index] = - nums[index];
        }
        
        int miss = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] > 0 && (i+1) != dup) {
                miss = i+1;
                return {dup , miss};
            }       
        }
        
        return {dup , miss};
    }
};
