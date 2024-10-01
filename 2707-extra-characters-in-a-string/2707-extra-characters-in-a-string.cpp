class Solution {
private:
    int helper(string s, int i, unordered_set<string> &mp,  vector<int> &dp) {
        if(i >= s.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        // count as extra
        int minExtra = 1 + helper(s, i+1 , mp , dp);
        
        // all possible substrings starting from current index
        for(int end = i+1 ; end <= s.size() ; end++) {
            string temp = s.substr(i , end - i);
            
            if(mp.find(temp) != mp.end()) {
                minExtra = min(minExtra , helper(s , end , mp, dp));
            }
        }
        
        return dp[i] = minExtra;
    }
    
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        vector<int> dp(s.size() + 1, -1);
        unordered_set<string> mp(dictionary.begin(), dictionary.end());
        
        return helper(s, 0, mp , dp);

    }
};