class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int flag = 1; // is positive
        int i = 0;
        
        
        // skip the whitespacec
        while(i < s.size() && s[i] == ' ') {
            i++;
        }
        
        // check for the +/- sign
        if(i < s.size() && s[i] == '-') {
            flag = -1;
            i++;
        }
        else if(i < s.size() && s[i] == '+') {
            i++;
        }
        
        // check for the number
        long long result = 0;
        while(i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');
            
            // checking for integer overflow
            if(result * flag > INT_MAX) {
                return INT_MAX;
            }
            else if(result * flag < INT_MIN) {
                return INT_MIN;
            }
        }
        
        
        return result*flag;
    }
};