class Solution {
    
private:
    void solve(vector<int> &arr,int i, vector<vector<int>> &ans , vector<int> temp) {
        if(i == arr.size()) {
            ans.push_back(temp);
            return;
        }
        
        // do not take it
        solve(arr, i+1 , ans , temp);
        
        // take it
        temp.push_back(arr[i]);
        solve(arr, i+1 , ans, temp);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        solve(nums,0, ans, temp);
        
        return ans;
    }
};