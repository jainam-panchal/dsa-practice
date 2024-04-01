class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum = 0 , maxi = -DBL_MAX;
        int n = nums.size();

        int i = 0, j = 0;
        
        while(j < n) {
            sum += nums[j];
            
            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                double currAvg = sum / k;
                maxi = max(maxi, currAvg);
                
                sum -= nums[i];
                i++; j++;
            }
        }
        
        return maxi;
        
    }
};