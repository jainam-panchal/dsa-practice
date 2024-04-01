class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int n = s.size(), k = 3;
        vector<int> map(26, 0);
        int result = 0 , distinctEle = 0;
        
        int i=0, j=0;
        
        while(j < n) {
            if(map[s[j] - 'a'] == 0) {
                distinctEle++;
            }
            map[s[j] - 'a']++;
            
            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                if(distinctEle == 3) result++;
                
                map[s[i] - 'a']--;
                if(map[s[i] - 'a'] == 0) distinctEle--;
                
                i++;
                j++;
            }        
        }
        
        return result;
    }
};