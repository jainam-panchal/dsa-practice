class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int total_xor = 0;
        for(auto i : nums) {
            total_xor ^= i;
        }
        
        int temp = total_xor;
        
        // find rightmost set bit
        int set_bit = 0;
        while(1) {
            if((temp & 1) == 1) {
                break;
            } 
            set_bit++;
            temp = temp>>1;
        }
        
        int mask = 1 << set_bit;
        int group_a = 0;
        int group_b = 0;
        
        for(auto i : nums) {
            if(mask & i) {
                group_a ^= i;
            }
            else {
                group_b ^= i;
            }
        }
        return {group_a, group_b};
    }
};