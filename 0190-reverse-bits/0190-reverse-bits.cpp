class Solution {
private:
    bool findKthBitSet(unsigned int A, int k) {
        if (((1 << (k-1))&A)!=0) return true;
        return false;
    }
public:
    
    uint32_t reverseBits(uint32_t A) {
        
        // modifying this according to input
        uint32_t ans = 0;
        
        for(int i=1; i<=32 ; i++) {
            
            if(findKthBitSet(A,i)){
                // change curresponding bit in ans
                ans = 1 << (32-i) | ans;
            }
        }
        
        return ans;
    }
};