class Solution {
public:
    int check(string &s, int i, int j){
        int ans = 0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
        return ans;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            ans += check(s, i, i);
            ans += check(s, i, i+1);
        }
        return ans;
    }
};
