class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.size();
        int index=-1;
        
        for(int i=n-1 ; i>=0 ; i--) {
            int value = num[i] - '0';
            if(value % 2 != 0) {
                index = i;
                break;
            }
        }
        
        string ans = "";
        for(int i=0 ; i<=index ; i++) {
            ans += num[i];
        }
        return ans;
    }
};