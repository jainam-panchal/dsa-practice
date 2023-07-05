class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // start with first row and last col
        //    [/]these two points

        int row = 0;
        int col = matrix[0].size()-1;
        
        while(row < matrix.size() && col>=0) {
            int value = matrix[row][col];
            if(value == target) {
                matrix.clear();
                return 1;
            }
            else if(value < target) {
                // because we won't find any value greater than the value in that row
                row++;
            }
            else {
                // because  we won't find any value smaller than the value columns after that
                col--;
            }
        }

        matrix.clear();
        return 0;
    }
};
