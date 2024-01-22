class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {        
        unordered_map<int, int> hash;
        for(auto a : nums) {
            if(hash.find(a) != hash.end())
                hash[a]++;
            else
                hash[a] = 1;
        }
        
        int dup = 0;
        int mis = 0;
        
        for(int i=1 ; i<=nums.size() ; i++) {
            if(hash.find(i) != hash.end()) {
                if(hash[i] == 2)
                    dup = i;
            }
            else
                mis = i;
        }
        
        return {dup ,mis};
    }
};