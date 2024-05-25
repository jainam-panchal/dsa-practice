class Solution {
private:
    int n;
    unordered_set<string> st;
    
    void helper(int idx, string curr , string &s , vector<string> &ans) {
        if(idx == n) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        
        for(int i=1 ; i<=n-idx ; i++) {
            string temp = s.substr(idx, i);
            if(st.find(temp) != st.end()) {
                helper(idx+i , curr + temp + " ", s, ans);
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto val : wordDict) {
            st.insert(val);
        }
        
        string temp;
        vector<string> ans;
        helper(0 , temp , s ,ans);
        
        return ans;
    }
};