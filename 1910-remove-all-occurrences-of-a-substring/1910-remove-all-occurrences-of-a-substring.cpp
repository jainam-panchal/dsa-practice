class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        // till length!=0 and part is present in string
        while(s.length() != 0 && s.find(part) <= s.length()) {
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};