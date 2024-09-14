class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = queries.size();
        vector<int> ans(n), prefix(arr.size());
        
        prefix[0] = arr[0];
        for(int i=1 ; i<arr.size() ; i++) {
            prefix[i] = prefix[i-1] ^ arr[i];
        }
        
        for(int i=0 ; i<n ; i++) {
            
            int left = queries[i][0] , right = queries[i][1];
            if (left == 0) {
                ans[i] = prefix[right];  // When left is 0, the answer is just prefix[right]
            } else {
                ans[i] = prefix[right] ^ prefix[left - 1];  // General case
            }

        }
        
        return ans;
        
    }
};