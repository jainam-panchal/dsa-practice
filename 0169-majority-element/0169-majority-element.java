class Solution {
    public int majorityElement(int[] nums) {
        
        // Moore Voting Algo
        
        int candidate = -1  , count = 0;
        
        for(int ind = 0 ; ind<nums.length ; ind++) {
            if(count == 0) {
                candidate = nums[ind];
                count = 1;
            } else {
                if(nums[ind] == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        
        return candidate;
    }
}