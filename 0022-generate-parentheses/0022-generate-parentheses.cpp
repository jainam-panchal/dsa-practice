class Solution {
private:
    void generate(vector<string> &ans , int open , int close, string curr) {
        if(open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(open == close) {
            generate(ans, open-1, close, curr+'(');
            return;
        }
        
        // two opt
        else {
            if(open != 0)
                generate(ans, open-1, close, curr+'(');
            generate(ans, open, close-1 , curr+')');
            return;
        }

    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        
        string curr = "";
        generate(ans, open, close, curr);
        
        return ans;
    }
};