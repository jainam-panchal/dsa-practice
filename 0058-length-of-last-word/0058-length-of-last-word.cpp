class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size()-1;
        int flag = 0;
        int ans = 0;
        
        for(int i=size ; i>= 0 ; --i) {
            if(s[i] == ' ' && flag)
                break;
            if(s[i] != ' ') {
                flag = 1;
                ans ++;
            }
        }
        
        return ans;
    }
};