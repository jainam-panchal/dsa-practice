class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        // BRUTEFORCE APPROACH - O(N^2)
        // int ans = -1;
        // for(int i=0 ; i<s.size() ; i++) {
        //     for(int j=i+1 ; j<s.size() ; j++) {
        //         if(s[i] == s[j]) 
        //             ans = max(ans, j - i - 1);
        //     }
        // }
        
        // OPTIMAL - O(N)
        unordered_map<char,int> hashmap;
        int ans = -1;
        
        for(int i=0; i<s.length() ; i++) {
            if(hashmap.find(s[i]) != hashmap.end()) {
                ans = max(ans , i - hashmap[s[i]] - 1);
            }
            else {
                hashmap[s[i]] = i;
            }
        }
        
        return ans;
    }
};