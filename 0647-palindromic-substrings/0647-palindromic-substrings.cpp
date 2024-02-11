class Solution {
public:
    bool checkPalindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i > j) return true;
        
        if(dp[i][j] != -1) {
            return dp[i][j] == 1 ? true : false;
        }
        
        bool flag = false;
        
        if(s[i] == s[j]) {
            flag = flag | checkPalindrome(s, i+1, j-1, dp);
        }
        
        dp[i][j] = flag ? 1 : 0;
        return  flag;
    }
    
    int countSubstrings(string s) {
        
        // BRUTEFORCE
        // get all substrings
        // check palindrome for every substring
        
        int count = 0;
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n,-1));
        
        for(int i=0 ; i<n ; i++) {
            for(int j=i ; j<n ; j++) {
                if(checkPalindrome(s,i,j,dp))
                    count++;
            }
        }
        
        return count;
    }
};