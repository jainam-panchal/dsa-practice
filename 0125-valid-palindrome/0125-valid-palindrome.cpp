class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        string result = "";
        
        for (char c : s) {
            if (isalnum(c)) {
                result += tolower(c);
            }
        }
        
        int start = 0, end = result.size() - 1;
        while(start < end) {
            if(result[start++] != result[end--])
                return false;
        }
        
        return true;
    }
};