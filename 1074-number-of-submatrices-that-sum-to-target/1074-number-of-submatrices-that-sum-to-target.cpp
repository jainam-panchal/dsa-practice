class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& m, int target) {
        
        int result = 0;
        int rows = m.size();
        int cols = m[0].size();
        
        for(int row = 0 ; row < rows ; row++) {
            for(int col = 1 ; col < cols ; col++) {
                m[row][col] += m[row][col-1];
            }
        }
        
        // pick the corner
        for(int startCol = 0 ; startCol < cols ; startCol++) {
            
            // from the corner, iterate through all cols
            for(int currCol = startCol ; currCol < cols ; currCol++) {
                
                unordered_map<int,int> map;
                map[0] = 1;         // for the edge case
                int sum = 0;
                
                for(int row = 0 ; row < rows ; row++) {
                    
                    // add the cummulative sum and remove the sum before startCol
                    sum += m[row][currCol] - (startCol > 0 ? m[row][startCol-1] : 0);
                    if(map.count(sum - target)) {
                        result += map[sum - target];
                    }
                    
                    map[sum]++;
                }
                
            }
        }
        
        return result;
    }
};