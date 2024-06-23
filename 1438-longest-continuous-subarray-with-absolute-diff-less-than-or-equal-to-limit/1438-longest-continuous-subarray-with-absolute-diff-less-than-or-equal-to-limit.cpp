class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> maxq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;

        int i=0, j=0, len=0;
        int n=nums.size();
        
        while (j < n) {
            maxq.push({nums[j] , j});
            minq.push({nums[j] , j});
            
            while(maxq.top().first - minq.top().first > limit) {
                i = min(maxq.top().second , minq.top().second) + 1;
                
                while(maxq.top().second < i) maxq.pop();
                while(minq.top().second < i) minq.pop();
            }
            
            len = max(len , j-i+1);
            j++;
        }
        
        return len;
    }
};