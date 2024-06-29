class Solution {
private:
    void dfs(int grandpa , int currNode , unordered_map<int, vector<int>> &mp, vector<vector<int>> &result) {
        for(auto i : mp[currNode]) {
            if(result[i].empty() || result[i].back() != grandpa) {
                result[i].push_back(grandpa);
                dfs(grandpa , i , mp , result);
            }
        }
    }
    
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(auto &i : edges) {
            int from = i[0];
            int to = i[1];
            
            mp[from].push_back(to);
        }
        
        vector<vector<int>> ans(n);
        
        for(int i=0 ; i<n ; i++) {
            int grandpa = i;
            dfs(grandpa , i ,  mp , ans);
        }
        
        
        return ans;
        
    }
};