class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // variable size sliding window
        int l=0, r=0, maxi=0;
        unordered_map<char, int> map;
       
        while(r < s.size()) {
            
            // if found in map
            if(map.find(s[r]) != map.end() && map[s[r]] >= l) {
                l = map[s[r]]+1;
            }
            
            // adding entry
            map[s[r]] = r;
            
            // updating maxi
            maxi = max(maxi , r-l+1);
            
            r++;
            
        }
        
        
        return maxi;
    }
};