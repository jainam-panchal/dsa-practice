class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
     
        // becuase of the constraint 1<=nums[i]<=nums.length
        vector<int> freq(nums.size()+1);
        
        vector<vector<int>> ans;
        
        // iterate over the array and check the freq
        for(int value : nums) {
            
            if(freq[value] == ans.size()) {
                ans.push_back({});
            }
            
            ans[freq[value]].push_back(value);
            freq[value]++;
        }
        
        return ans;
    }
};