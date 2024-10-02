class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> mp;
        
        for(int i=0 ; i<arr.size() ; i++) {
            mp[arr[i]].push_back(i);
        }

        
        int rank = 1;
        vector<int> ans(arr.size() , 0);
        for(auto& entry : mp) {
            
            for(int index : entry.second) {
                ans[index] = rank;
            }
            
            rank++;
        }
        
        return ans;
    }
};