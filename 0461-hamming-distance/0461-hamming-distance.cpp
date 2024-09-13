class Solution {
public:
    int hammingDistance(int x, int y) {
        int xored = x ^ y;
        
        int count = 0;
        while(xored) {
            if(xored & 1 == 1) {
                count++;
            }
            
            xored = xored >> 1;
        }
        
        return count;
    }
};