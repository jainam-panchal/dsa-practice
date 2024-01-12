class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.size()/2;
        int total = 0;
        
        int i = 0;
        for(i=0 ; i<s.size()/2; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                total++;
            }
        }
        
        for( ; i<s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                total--;
            }
        }
        
        if(!total) return true;
        
        return false;
    }
};