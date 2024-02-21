class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int count = 0;
        while(left != right) {
            left = left >> 1;
            right = right >> 1;
            count++;
        }
        
        // left and right would be equal
        return (left << count);
        
    }
};