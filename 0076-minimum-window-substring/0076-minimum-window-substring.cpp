class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        
        // not possible
        if(t.size() > n) return "";
        
        // hashmap for t
        unordered_map<char, int> mp;
        for(auto ch : t) {
            mp[ch]++;
        }
        
        int required = t.size();
        int minWindowSize = INT_MAX;
        int start_i = 0;
        
        int i=0;
        int j=0;
        
        while(j < n) {
            
            // for every visited char, decrese the count;
            char ch = s[j];
            if(mp[ch] > 0)
                required--;
            mp[ch]--;
            
            // HIT - Found a window
            while(required == 0) {
                // try shrinking it from i
                int currWindowSize = j - i + 1;
                
                // if it's smaller than the global
                if(minWindowSize > currWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }
                
                // start moving i
                mp[s[i]]++;
                
                // if we wanted this
                if(mp[s[i]] > 0) {
                    required++;
                }
                
                i++;
            }
            
            
            j++;
        }
        
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};