class Solution {
    void solve(vector<string>& ans, string current, int open, int close) {

        // base condition
        if(open == 0 && close == 0) {
            ans.push_back(current);
            return;
        }
        
        // only one choice, add one (
        if(open == close) {
            solve(ans, current+'(', open-1, close);
        }
        // two options, add ( or )
        else if(open < close) {
            if(open != 0)
                solve(ans,current+'(', open-1, close);
            solve(ans,current+')', open , close-1);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        solve(ans, "", n , n);
        return ans;
    }
};