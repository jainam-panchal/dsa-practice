class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        
        int count = 0;
        for(auto i : arr) {
            mp[i]++;
        }
        
        
        int current = 0;
        for(auto i : arr) {
            if(mp[i] == 1) {
                current++;
            }
            
            if(current == k) return i;
        }
        
        return "";
    }
};