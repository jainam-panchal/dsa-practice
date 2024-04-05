class Solution {
public:
    string makeGood(string s) {
        string ans;
        int n = s.size();
        
        for(int i=0 ; i<n ; i++) {
            
            // if it's empty, just push
            if(ans.size() == 0) {
                ans.push_back(s[i]);
            }
            // if adj characters are up-low
            else if(abs(ans.back() - s[i]) == 32) {
                ans.pop_back();
            }
            // nothing special
            else {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};