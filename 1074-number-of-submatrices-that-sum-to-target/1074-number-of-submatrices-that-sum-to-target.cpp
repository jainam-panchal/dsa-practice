class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& m, int target) {
        
        
        // prefix sum method
        int result = 0;
        int rows = m.size();
        int cols = m[0].size();
        
        // calc each row commulative sum
        // ex row : 1 2 3 to 1 3 6
        for(int row=0 ; row<rows ; row++) {
            for(int col=1 ; col<cols ; col++) {
                m[row][col] = m[row][col] + m[row][col-1];
            }
        }
        
        // just like Leetcode - 560, but while iterating through each ele in row horizontally
        // iterate through the column 
        for(int startingCol = 0 ; startingCol < cols ; startingCol++) {
            
            for(int curCol = startingCol ; curCol < cols ; curCol++) {
                
                // now go through each elem in col
                int sum = 0;
                unordered_map<int,int> mp;
                mp[0] = 1;
                
                for(int row= 0; row<rows ; row++) {
                    // we consider all left side of the element in the commulative sum so
                    // we need to subtract the prev element to get the current element
                    sum += m[row][curCol] - (startingCol > 0 ? m[row][startingCol-1] : 0);
                    if(mp.count(sum - target)) {
                        result += mp[sum - target];
                    }
                    
                    mp[sum]++;
                    
                }
                
            }
            
        }
        
        return result;
    }
};