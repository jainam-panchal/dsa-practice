class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans; 
        int row = matrix.size(), col = matrix[0].size(), totalCount = row*col;
        int count = 0;

        int firstRow = 0;
        int lastCol = col-1;
        int lastRow = row-1;
        int firstCol = 0;

        while(count < totalCount) {
            
            // adding first row
            for(int index=firstCol ; count<totalCount && index<=lastCol ; index++) {
                ans.push_back(matrix[firstRow][index]); count++;
            }
            firstRow++;

            // adding last col
            for(int index=firstRow ; count<totalCount && index<=lastRow ; index++) {
                ans.push_back(matrix[index][lastCol]); count++;
            }
            lastCol--;

            // adding last row
            for(int index=lastCol ; count<totalCount && index>=firstCol ; index--) {
                ans.push_back(matrix[lastRow][index]); count++;
            }
            lastRow--;

            // adding first col
            for(int index=lastRow ; count<totalCount && index>=firstRow ; index--) {
                ans.push_back(matrix[index][firstCol]); count++;
            }
            firstCol++;

        }
        return ans;
    }
};