class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequency;

        for (int num : arr) {
            frequency[num]++;
        }

        // Convert the unordered_map to a vector of pairs
        vector<pair<int, int>> result(frequency.begin(), frequency.end());
        
        sort(result.begin() , result.end() , [](const pair<int,int> &lhs, const pair<int,int> &rhs){
            return lhs.second < rhs.second;
        });
        
        int i=0;
        while(k) {
            if(result[i].second == 0) {
                i++;
            }
            else {
                result[i].second--;
                k--;
            }
            
        }
        
        int count = 0;
        for(auto it=result.begin() ; it != result.end() ; it++) {
            if(it->second != 0) count++;
        }
        
        return count;
        
    }
};