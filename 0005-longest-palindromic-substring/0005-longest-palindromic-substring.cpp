class Solution {

private:
    int dp[1001][1001];
    
    bool checkPali(string &s , int i, int j) {
        if(i > j) return true;
        
        if(dp[i][j] != -1) {
            return dp[i][j] == 1 ? true : false; 
        }
        
        bool flag = false;
        if(s[i] == s[j]){
            flag = flag | checkPali(s, i+1 , j-1);
        }
        
        dp[i][j] = flag ? 1 : 0;
        return flag;
    }
    
public:
        
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        int maxi = -1;
        string ans = "";
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(checkPali(s, i, j) && (j-i+1) > maxi) {
                    maxi = j - i + 1;
                    ans = s.substr(i,maxi);
                }
            }
        }
        
        return ans;
    }
};