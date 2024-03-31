class Solution {
private:
    int findxthsmallest(vector<int> &count, int x) {
        int sum = 0;
        // only considering negatives
        for(int i=0 ; i<50 ; i++) {
            sum += count[i];
            if(sum >= x) {
                return i-50;
            }
        }
        // default
        return 0;
    }

public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        vector<int> count(101, 0);
        
        // setup the window
        for(int i=0 ; i<k ; i++) {
            count[nums[i] + 50]++;
        }
        ans[0] = findxthsmallest(count , x);
        
        for(int i=k,  j=1 ; i<n ; i++, j++) {
            count[nums[i] + 50]++;
            count[nums[i-k] + 50]--;
            
            ans[j] = findxthsmallest(count ,x);
        }
        
        return ans;
        
    }
};