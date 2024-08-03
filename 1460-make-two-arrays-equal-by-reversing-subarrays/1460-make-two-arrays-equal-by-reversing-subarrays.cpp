class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> hash;
        for(auto i : arr) {
            hash[i]++;
        }
        
        for(auto i : target) {
            if(hash[i] < 1) return false;
            hash[i]--;
        }

        return true;
    }
};