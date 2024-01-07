class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        vector<int>allChar(26, 0);
        
        for(int i=0 ; i<s.size() ; i++) {
            allChar[s[i] - 'a']++;
            allChar[t[i] - 'a']--;
        }
        
        for(int i=0 ; i<26 ; i++) {
            if(allChar[i] != 0) return false;
        }
        return true;
    }
};