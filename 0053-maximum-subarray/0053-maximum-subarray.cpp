class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // Kadane's algo
        
        int max_sum = nums[0];
        int current_sum = max_sum;
        
        for(int i=1 ; i<nums.size() ; i++) {
            
            // check if the current element helps 
            // the sum or not
            current_sum = max(current_sum + nums[i] , nums[i]);
            
            // update the max
            max_sum = max(max_sum,current_sum);
            
        }
        
        return max_sum;
    }
};