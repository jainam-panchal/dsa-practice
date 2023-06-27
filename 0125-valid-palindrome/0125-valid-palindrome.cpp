class Solution {
public:
    bool isPalindrome(string s) {
        int end = s.size()-1;
        int start = 0;
        
        while(start < end) {
            if(!isalnum(s[start]) || s[start] == ' ')
            {
                // cout << "not alnum s++" << endl;
                start++;
                continue;
            }
            if(!isalnum(s[end]) || s[end] == ' '){
                // cout << "not alnum e--" << endl;
                end--;
                continue;
            }
            
            char a = tolower(s[start]);
            // cout << " a is " << a << endl;
            char b = tolower(s[end]);
            // cout << " b is " << b << endl;
            
            if(a != b){
                // cout << "a != b" <<endl;
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
};