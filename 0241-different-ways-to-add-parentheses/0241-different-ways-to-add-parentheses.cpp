class Solution {
private:
    vector<int> solve(string s) {
        vector<int> result;
        
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left = solve(s.substr(0,i));
                vector<int> right = solve(s.substr(i+1));
                
                for(auto &x : left) {
                    for(auto &y : right) {
                        if(s[i] == '+') result.push_back(x+y);
                        else if(s[i] == '-') result.push_back(x-y);
                        else if(s[i] == '*') result.push_back(x*y);
                    }
                }
                
            }
        }
        
        if(result.empty()) result.push_back(stoi(s));
        
        return result;
        
    }
    
public:
    vector<int> diffWaysToCompute(string s) {
        return solve(s);
    }
};