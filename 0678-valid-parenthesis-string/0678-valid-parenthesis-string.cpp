class Solution {
private:
    bool solve(string &s, int i, int open , vector<vector<int>> &dp, int n) {
        if(i == n) return open == 0;

        if(dp[i][open] != -1) {
            return dp[i][open] == 1 ? true : false;
        }

        bool flag = false;
        
        if(s[i] == '*') {
            flag |= solve(s, i+1, open+1, dp, n);

            flag |= solve(s, i+1, open, dp, n);

            if(open > 0) flag |= solve(s, i+1, open-1, dp, n); 
        }
        else if(s[i] == '(') {
            flag |= solve(s, i+1 , open+1 , dp, n);
        }
        else if(open > 0) {
            flag |= solve(s, i+1, open-1, dp, n);
        }


        return dp[i][open] = flag ? 1 : 0;
    }
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return solve(s, 0, 0, dp, s.size());
    }
};