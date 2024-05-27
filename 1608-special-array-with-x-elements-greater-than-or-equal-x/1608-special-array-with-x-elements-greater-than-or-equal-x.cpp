class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int i=1 ; i<=nums.size(); i++) {
            int count = 0;
            for(auto val : nums) {
                if(val >= i) count++;
            }
            
            if(count == i) return i;
        }
        
        return -1;
    }
};