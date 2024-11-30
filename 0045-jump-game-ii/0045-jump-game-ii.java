class Solution {
    
    public int helper(int[] nums , int pos , int[] dp) {
        if(pos >= nums.length - 1) {
            return 0;
        }
        
        if(dp[pos] != 10001) {
            return dp[pos];
        }
        
        for(int i=1 ; i<=nums[pos] ; i++) {
            dp[pos] = Math.min(dp[pos] , 1 + helper(nums , pos + i , dp));
        }
        
        return dp[pos];
    }
    
    public int jump(int[] nums) {
        
        int n = nums.length;
        int [] dp = new int[n];
        
        Arrays.fill(dp , 10001);
        
        return helper(nums , 0 , dp);
    }
}