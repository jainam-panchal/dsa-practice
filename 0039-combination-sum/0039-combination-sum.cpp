class Solution {
private:
    void solve(vector<int>& candidates, int target, int i, vector<int> &arr, vector<vector<int>>& ans) {
        if(i >= candidates.size()) {
            return;
        }
        
        if(target == 0) {
            ans.push_back(arr);
            return;
        }
        
        if(candidates[i] <= target) {
            arr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i , arr, ans);
            arr.pop_back();
        }
        
        // not take
        solve(candidates, target, i+1 , arr, ans);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> arr;
        vector<vector<int>> ans;
        solve(candidates, target , 0 , arr, ans);
        
        return ans;
        
    }
};