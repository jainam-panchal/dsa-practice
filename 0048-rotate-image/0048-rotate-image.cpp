class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        
        // transpose
        for(int i=0 ; i<size ; i++) {
            for(int j=0 ; j<i ; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // reversing each row
        for(int i=0 ; i<size ; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};