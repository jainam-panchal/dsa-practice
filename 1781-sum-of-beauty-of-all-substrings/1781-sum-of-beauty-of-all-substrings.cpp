class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i=0 ; i<n; i++) {
            // INIT THE MAP
            map<char, int> m;          
            for(int j=i ; j<n ; j++) {
                
                // ADD IT TO THE MAP
                m[s[j]]++;
                
                int minFreq = INT_MAX;
                int maxFreq = INT_MIN;
                
                // GET MIN MAX
                for(auto item:m) {
                    minFreq = min(minFreq , item.second);
                    maxFreq = max(maxFreq , item.second);
                }
                
                // UPDATE THE ANS
                ans += (maxFreq - minFreq);
            }
        }
        
        return ans;
    }
};