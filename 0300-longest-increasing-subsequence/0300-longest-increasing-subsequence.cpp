class Solution {
private:
    int f(int index , int prev_index, vector<int>& arr, int n, vector<vector<int>>& dp) {
        
        // DYNAMIC PROGRAMMING - Memoization

        // base condition
        if(index == n) return 0;

        if(dp[index][prev_index + 1] != -1)
            return dp[index][prev_index + 1];

        // if we don't include
        int len = 0 + f(index+1 , prev_index, arr , n, dp);

        // if it's the first one or it has increasing order. OP: SELECT/NOT
        if(prev_index == -1 || arr[index] > arr[prev_index]) {
            len = max(len , 1 + f(index+1 , index  , arr, n, dp));
        }

        dp[index][prev_index + 1] = len;
        return len;
    }


public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n+1, -1));
        return f(0 , -1 , nums , n, dp);

    }
};


// RECURSIVE

// class Solution {
// private:
//     int f(int index , int prev_index, vector<int>& arr, int n) {
        
//         // base condition
//         if(index == n) return 0;

//         // if we don't include
//         int len = 0 + f(index+1 , prev_index, arr , n);

//         // if it's the first one or it has increasing order. OP: SELECT/NOT
//         if(prev_index == -1 || arr[index] > arr[prev_index]) {
//             len = max(len , 1 + f(index+1 , index  , arr, n));
//         }

//         return len;
//     }


// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // vector<vector<int>> dp(n , vector<int>(n+1, -1));
//         return f(0 , -1 , nums , n);

//     }
// };