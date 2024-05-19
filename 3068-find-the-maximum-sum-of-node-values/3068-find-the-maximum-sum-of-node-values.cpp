class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int count = 0;
        int minLoss = INT_MAX;
        
        for(long long num : nums) {
            if((num ^ k) > num) {
                sum += num ^ k; 
                count++;
            } else {
                sum += num;
            }
            
            minLoss = min((long long)minLoss , abs((num^k) - num));

        }
        
        if(count%2 == 0)
            return sum;

        return sum - minLoss;
    }
};