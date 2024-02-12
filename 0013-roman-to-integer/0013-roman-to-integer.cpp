class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char, int> val = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int ans = 0;
        int i = 0;
        int n = s.size();
        
        while(i < n) {
            char current = s[i];
            
            if(i+1 < n && (val[s[i+1]]) > val[s[i]]) {
                // CASE : IV = 4 , subtract
                ans = ans - val[s[i]];

            }
            else {
                // CASE : VI = 6 , add
                ans = ans + val[s[i]];
            }
            
            i++;
        }
        
        return ans;
        
    }
};