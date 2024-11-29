class Solution {
    public int removeDuplicates(int[] nums) {
        
        int i=0 , j=0 , count = 0;
        int limit = 2;
        
        while(j < nums.length) {
            int current = nums[j];
            count = 0;
            
            while(j < nums.length && nums[j] == current) {
                count++;
                j++;
            }
            
            int canTake = Math.min(limit , count);
            
            // to fill up in between positions
            for(int k=0 ; k<canTake ; k++) {
                nums[i] = current;
                i++;
            }
        }
        
        return i;
    }
}