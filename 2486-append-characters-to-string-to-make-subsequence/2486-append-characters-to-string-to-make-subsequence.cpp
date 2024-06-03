class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        int m=s.size(), n=t.size();
        
        while(i<m && j<n) {
            if(s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        
        return n-j;
    }
};