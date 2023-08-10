class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // simple intuition
        if(s.length() != t.length()) 
            return false;
        
        unordered_map<char, char> mapS;
        unordered_map<char, char> mapT;
    
        for(int i = 0 ; i < s.size() ; i++) {
            
            // checking if entry exists then check if it's the same entry or not
            if(mapS[s[i]] && mapS[s[i]] != t[i])
                return false;
            if(mapT[t[i]] && mapT[t[i]] != s[i])
                return false;
            
            
            // mapping
            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        }
        
        return true;
    }
};