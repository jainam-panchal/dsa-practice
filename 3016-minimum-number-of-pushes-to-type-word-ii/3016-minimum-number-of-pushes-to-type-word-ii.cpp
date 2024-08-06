class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> count;
        for(auto i : word) {
            count[i]++;
        }
        
        vector<pair<int, char>> collection;
        for(auto i : count) {
            char ch = i.first;
            int count = i.second;
            
            collection.push_back({count , ch});
        }
        
        sort(collection.begin() , collection.end(), greater<>());
        
        int alloted = 0;
        int totalCost = 0 , times = 1;
        
        for(int i=0 ; i<collection.size() ; i++) {
            totalCost += collection[i].first * times;
            alloted++;
            if(alloted >= 8) {
                times++;
                alloted = 0;
            }
            // cout  << collection[i].second << "alloted " << collection[i].first << " . TC = " << totalCost << endl;
        }
        return totalCost;
    }
};