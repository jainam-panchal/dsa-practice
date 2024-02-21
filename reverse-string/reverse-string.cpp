class Solution {
private:
    void solve(vector<char>& s, int i) {
        if(i >= s.size()/2) {
            return;
        }
        
        int size = s.size();
        swap(s[i] , s[size-i-1]);
        solve(s, i+1);
    }
    
public:
    void reverseString(vector<char>& s) {
        solve(s, 0);
    }
};