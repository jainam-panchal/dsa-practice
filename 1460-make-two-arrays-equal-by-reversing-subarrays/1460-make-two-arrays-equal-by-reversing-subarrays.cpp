class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         unordered_map<int,int> hash;
//         for(auto i : arr) {
//             hash[i]++;
//         }
        
//         for(auto i : target) {
//             if(hash[i] < 1) return false;
//             hash[i--];
//         }
        
        sort(arr.begin() , arr.end());
        sort(target.begin() , target.end());
        
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i] != target[i]) return false;
        }
        
        return true;
    }
};