class Solution {
private:
    int dp[501];
    
    int solve(vector<int> &arr , int i, int k) {
        
        if(i >= arr.size()){
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int currMax = -1;
        int result = -1;
        
        for(int j=i ; j<arr.size() && j-i+1 <= k ; j++) {
            currMax = max(currMax, arr[j]);
            result = max(result , currMax * (j-i+1) + solve(arr , j+1, k));
        }
        
        return dp[i] = result;
        
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
            memset(dp, -1, sizeof(dp));
            return solve(arr, 0 , k);
    }
};