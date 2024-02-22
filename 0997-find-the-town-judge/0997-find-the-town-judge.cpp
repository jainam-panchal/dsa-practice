class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = -1;
        
        vector<int> trusted(n+1, 0);
        for(auto person : trust) {
            trusted[person[1]]++;
        }
        
        
        // Second Condition
        for(int i=1 ; i<trusted.size() ; i++) {
            if(trusted[i] == n-1 && ans == -1) {
                // cout << "setting ans" << endl;
                ans = i;
            }
        }
        
        // First Condition
        for(auto person : trust) {
            if(person[0] == ans) {
                return -1;
            }
        }
        
        return ans;
    }
};