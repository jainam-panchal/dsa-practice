class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // remove excess closing parentheses
        string str;
        int count = 0;
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == '(') {
                str += s[i];
                count++;
            }
            else if(s[i] == ')') {
                if(count != 0) {
                    str += s[i];
                    count--;
                }
            }
            else {
                str += s[i];
            }
        }
        
        if(count == 0) {
            return str;
        }
        
        count = 0;
        string ans;
        for(int i=str.size()-1 ; i>=0 ; --i) {
            if(str[i] == ')') {
                ans += str[i];
                count++;
            }
            else if(str[i] == '(') {
                if(count != 0) {
                    ans += str[i];
                    count--;
                }  
            }
            else {
                ans += str[i];
            }
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};