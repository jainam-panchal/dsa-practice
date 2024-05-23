class Solution {
private:
    int n;
    bool checkPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++; right--;
        }
        
        return true;
    }
        
    void backtrack(string &s, vector<vector<string>> &ans, vector<string> curr, int idx) {
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx ; i<n ; i++) {
            if (checkPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        
        
        backtrack(s, ans, temp, 0);
        return ans;
    }
};