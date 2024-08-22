class Solution {
public:
    int findComplement(int num) {
        int no_of_bits = (int)(log2(num)) + 1;
        
        // example : 1 << 3 => 1000 - 1 => 111
        unsigned int mask = (1U << no_of_bits) - 1;
        
        return num ^ mask;
    }
};