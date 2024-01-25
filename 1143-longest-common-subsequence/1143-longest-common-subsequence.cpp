class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        
        // fill up the first row and col
        for(int i=0 ; i<memo.size() ; i++) {
            memo[i][0] = 0;
        }
        for(int i=0 ; i<memo[0].size() ; i++) {
            memo[0][i] = 0;
        }
        
        for(int i=1 ; i<m+1 ; i++) {
            for(int j=1 ; j<n+1 ; j++) {
                // if equal char
                if(text1[i-1] == text2[j-1]) {
                    memo[i][j] = 1 + memo[i-1][j-1];
                }
                else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        
        return memo[m][n];
    }
};