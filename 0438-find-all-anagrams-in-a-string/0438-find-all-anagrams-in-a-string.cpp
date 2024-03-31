class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> strmp(26, 0);
        vector<int> patmp(26, 0);
        
        // hash for pattern
        for(auto ch : p) patmp[ch - 'a']++;
        
        int n = s.size();
        int i=0, j=0, k=p.size();
        vector<int> ans;
        
        while(j < n) {
            strmp[s[j] - 'a']++;
            
            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                // if we get match
                if(strmp == patmp) {
                    ans.push_back(i);
                }
                // slide the window
                strmp[s[i] - 'a']--;
                i++;
                j++;
            }
        }
        
        return ans;
        
    }
};