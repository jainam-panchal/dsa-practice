class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> rem;
        for(auto i : arr) {
            int val = ((i % k) + k) % k;
            rem[val]++;
        }

        if(rem[0] % 2 != 0) return false;

        for(int i=1 ; i<k ; i++) {
            if(rem[i] != rem[k - i]) return false;
        }
        
        return true;    
    }
};