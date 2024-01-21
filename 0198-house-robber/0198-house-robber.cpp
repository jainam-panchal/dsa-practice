class Solution {
public:
    
    // TABULAR
    
    int rob(vector<int>& nums) {
        //tb[i] means max steal of i houses
        vector<int> tb(nums.size()+1);
        
        // no house max profit
        tb[0] = 0;
        
        // one house max profit
        tb[1] = nums[0];
        
        for(int i=2 ; i<= nums.size() ; i++) {
            int steal = nums[i-1] + tb[i-2];
            int skip = 0 + tb[i-1];
            
            tb[i] = max(steal , skip);
        }
        
        return tb[nums.size()];
    }
};


// MEMOIZATION

// class Solution {
// public:
//     
//     int t[101];
//     int solve(vector<int>& nums, int i , int n) {
//         if(i >= n)
//             return 0;
        
//         if(t[i] != -1)
//             return t[i];
        
//         int steal = nums[i] + solve(nums, i+2, n);
//         int skip = 0 + solve(nums, i+1, n);
        
//         return t[i] = max(steal , skip);
//     }
    
//     int rob(vector<int>& nums) {
//         memset(t, -1, sizeof(t));
//         int n = nums.size();
        
//         return solve(nums, 0 ,n);
//     }
// };