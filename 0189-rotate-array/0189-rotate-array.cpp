class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // First Approach
        vector<int> temp(n);

        // Using % operator
        for(int i=0 ; i<n ; i++)
        {
            temp[(i+k)%n] = nums[i];
        }

        // Copy content to original vector
        for(int i=0 ; i<n ; i++)
        {
            nums[i] = temp[i];
        }
        
        return;
    }
};