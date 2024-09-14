class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> ans(queries.size());
        
        for(int i=0 ; i<queries.size() ; i++) {
            int left = queries[i][0] , right = queries[i][1];
            
            int val = arr[left]; left++;
            while(left <= right){
                val = val ^ arr[left];  
                left++;
            }
            
            ans[i] = val;
        }
        
        return ans;
    }
};