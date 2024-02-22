class Solution {
private:
    int nCr(int n, int r) {
        long long ans = 1;
        
        for(int i=0 ; i<r ; i++) {
            ans = ans * (n-i);
            ans = ans / (i+1);
        }
        
        return (int) ans;
    }
    
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int row=1 ; row <= numRows ; row++) {
            vector<int> temp;
            for(int col=1 ; col <= row ; col++) {
                temp.push_back(nCr(row - 1, col - 1));
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};