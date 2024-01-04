class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int num = 1;
        
        int i=0;
        int n=nums.size();
        
        while(i < n && k > 0) {
            // not missing
            if(nums[i] == num) {
                i++;
            }
            // missing
            else {
                k--;
            }
            num++;
        }
        
        // edge case
        // {1,2,3}, k=2
        while(k--) {
            num++;
        }
        
        return num-1;
    }
};