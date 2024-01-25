class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return lcsMemo(text1, text2, 0, 0, memo);
    }

private:
    int lcsMemo(string& str1, string& str2, int m, int n, vector<vector<int>>& memo) {
        if(m >= str1.size() || n >= str2.size()) {
            return 0;
        }
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(str1[m] == str2[n])
            return 1 + lcsMemo(str1, str2, m+1, n+1, memo);
        
        int first = lcsMemo(str1, str2, m+1 , n, memo);
        int second = lcsMemo(str1, str2, m, n+1 , memo);

        return memo[m][n] = max(first,second);
        
    }
};