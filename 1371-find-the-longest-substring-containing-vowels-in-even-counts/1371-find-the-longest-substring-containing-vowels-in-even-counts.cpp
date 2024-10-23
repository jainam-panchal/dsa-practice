class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> mp;
        
        int mask = 0;
        int ans = 0;
        mp[mask] = -1;
        
        for(int i=0 ; i<s.size() ; i++) {
            char ch = s[i];
            
            if(ch == 'a') {
                mask = mask ^ (1 << 1);
            } else if(ch == 'e') {
                mask = mask ^ (1 << 2);
            } else if(ch == 'i') {
                mask = mask ^ (1 << 3);
            } else if(ch == 'o') {
                mask = mask ^ (1 << 4);
            } else if(ch == 'u') {
                mask = mask ^ (1 << 5);
            }
            
            if(mp.find(mask) != mp.end()) {
                ans = max(ans , i - mp[mask]);
            } else {
                mp[mask] = i;
            }
        }
        
        return ans;
    }
};