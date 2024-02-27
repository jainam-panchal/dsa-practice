class Solution {
private:
    vector<vector<int>> ans;
    
    void solve(int ind, int target, vector<int>& candidates, vector<int>& arr, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(arr);
        }
        
        for(int i = ind ; i<candidates.size() ; i++) {
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            arr.push_back(candidates[i]);
            solve(i+1 , target-candidates[i], candidates, arr, ans);
            arr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> ans;
        sort(candidates.begin() , candidates.end());
        solve(0 , target, candidates, arr, ans);
        return ans;
    }
};