class Solution {
private:
    int helper(int i , int j , string &s , string &t , vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1])
            return dp[i][j] = 1 + helper(i-1 , j-1 , s , t , dp);
        
        return dp[i][j] = max(
            helper(i-1 , j , s , t , dp),
            helper(i , j-1 , s , t , dp)
        );
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin() , t.end());
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        return n - helper(n , n , s , t, dp);
    }
};