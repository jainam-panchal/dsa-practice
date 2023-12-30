class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        
        
        int row=arr.size();
        int col=arr[0].size();
        
        vector<bool> rowZero(row), colZero(col);
        
        // mark zeros
        for(int i=0 ; i<row ; i++) {
            for(int j=0 ; j<col ; j++) {
                if(arr[i][j] == 0) {
                    rowZero[i] = colZero[j] = true;
                }
            }
        }
        
        // fill row zeros
        for(int i=0 ; i<row ; i++) {
            if(rowZero[i]) fill(arr[i].begin(), arr[i].end(), 0);
        }
        // fill column zeros
        for(int j=0 ; j<col ; j++) {
            if(colZero[j]) {
                for(int i=0 ; i<row; i++) {
                    arr[i][j] = 0;
                }
            }
        }
    }
};