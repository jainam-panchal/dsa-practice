class Solution {
public:
    bool checkPalindrome(string &s, int i, int j) {
        if(i > j) return true;
        
        if(s[i] == s[j])
            return checkPalindrome(s, i+1, j-1);
        
        return false;
    }
    
    int countSubstrings(string s) {
        
        // BRUTEFORCE
        // get all substrings
        // check palindrome for every substring
        
        int count = 0;
        int n = s.size();
        
        for(int i=0 ; i<n ; i++) {
            for(int j=i ; j<n ; j++) {
                if(checkPalindrome(s,i,j))
                    count++;
            }
        }
        
        return count;
    }
};