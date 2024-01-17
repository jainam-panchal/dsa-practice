class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        string mini = *min_element(strs.begin(), strs.end());
        
        for(int i=0 ; i<mini.size() ; i++) {
            // get the curr element to compare
            char currChar = mini[i];
            
            // iterate over the vector and compare
            bool flag = true;
            for(int j=0 ; j<strs.size(); j++) {
                if(strs[j][i] != currChar) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans = ans + currChar;
            else break;
        }
        
        return ans;
    }
};