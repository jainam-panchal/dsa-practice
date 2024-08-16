class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int result = 0;
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        
        for(int i=1 ; i<arrays.size() ; i++) {
            result = max(result , abs(maxi - arrays[i].front()));
            result = max(result , abs(arrays[i].back() - mini));
            
            mini = min(mini , arrays[i][0]);
            maxi = max(maxi , arrays[i].back());
        }
        
        return result;
    }
};