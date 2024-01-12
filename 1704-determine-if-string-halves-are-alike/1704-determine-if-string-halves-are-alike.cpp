class Solution {
public:
    bool halvesAreAlike(string s) {
        
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int midPoint = s.size()/2;
        
        int total = 0;
        
        for(int i=0 ; i<s.size()/2 ; i++) {                
            if(vowels.count(s[i])) total++;
            if(vowels.count(s[midPoint])) total--;   
            
            midPoint++;
        }
        
        if(!total) return true;
        return false;
        
    }
};