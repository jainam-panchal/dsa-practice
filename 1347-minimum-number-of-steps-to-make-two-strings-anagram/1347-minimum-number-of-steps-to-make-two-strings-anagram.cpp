class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s1(26 , 0);
        vector<int> s2(26 , 0);
        
        // count freq
        for(int i=0 ; i<s.size() ; i++) {
            s1[s[i] - 'a']++;
            s2[t[i] - 'a']++;
        }
        
        int ans = 0;
        
        // calc no of changes required 
        for(int i=0 ; i<26 ; i++) {
            int diff = abs(s1[i] - s2[i]);
            ans += diff;
        }
        
        // we have counted one swap in two steps so
        return ans/2;
    }
};