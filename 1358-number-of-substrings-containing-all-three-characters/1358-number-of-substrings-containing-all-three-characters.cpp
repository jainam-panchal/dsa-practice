class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int ans = 0;
        vector<int> lastseen = {-1 , -1 , -1};
        
        for(int i=0 ; i<s.size() ; i++) {
            lastseen[s[i] - 'a'] = i;
            
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                ans += 1 + *min_element(lastseen.begin(), lastseen.end());
            }
        }
        
        return ans;
        
    }
};