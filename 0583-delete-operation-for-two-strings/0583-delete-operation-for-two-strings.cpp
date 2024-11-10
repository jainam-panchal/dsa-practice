class Solution {
private:
    int helper(int i , int j , string s , string t , vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1]) return dp[i][j] = 1 + helper(i-1 , j-1 , s , t , dp);
        
        return dp[i][j] = max(
            helper(i-1 , j , s , t , dp),
            helper(i , j-1 , s , t , dp)
        );
    }
    
    
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        return (n+m) - 2 * helper(n , m , word1 , word2 , dp);
        
    }
};