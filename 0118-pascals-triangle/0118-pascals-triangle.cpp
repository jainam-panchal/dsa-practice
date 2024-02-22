class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        
        if(numRows == 1) {
            return ans;
        }
        
        for(int i=1 ; i<numRows ; i++) {

            vector<int> curr(i+1, 0);
            ans.push_back(curr);
            
            for(int j=0 ; j<=i ; j++) {
                int left = (j - 1 >= 0) ? ans[i - 1][j - 1] : 0;
                int right = (j < i) ? ans[i - 1][j] : 0;
                
                ans[i][j] = (left+right);
            }
        }
        
        return ans;
        
    }
};