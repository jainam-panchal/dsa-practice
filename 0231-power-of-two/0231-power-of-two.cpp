class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n == 1) {
            return true;
        }
        
        if(n <= 0) {
            return false;
        }
        
        // if the number is power of binary then it will only have one set bit
        // 4 = 100 , 3 = 11
        // 16 = 10000, 15 = 1111
        // if we do and then the ans would be 0
        
        return (n & (n-1)) == 0;
    }
};