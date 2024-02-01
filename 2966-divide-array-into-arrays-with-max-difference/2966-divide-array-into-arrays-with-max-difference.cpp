class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        
        int curr=0;
        int n = nums.size() / 3; // total number of possible subarray
        
        for(int i = 0 ; i<n ; i++) {
            vector<int> temp;
            for(int j=0 ; j<3 ; j++) {
                temp.push_back(nums[curr++]);
            }
            if(temp[2] - temp[0] <= k) {
                ans.push_back(temp);
            }
            else {
                ans.clear();
                return ans;
            }
        }
        
        return ans;
    }
};