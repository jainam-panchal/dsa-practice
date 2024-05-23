class Solution {
private:
    int n;
    int result;

    void backtrack(int i, int &k , vector<int> &nums, unordered_map<int, int> &mp) {
        if(i >= n) {
            result++;
            return;
        }
        
        // two opt : take it or not
        backtrack(i+1 , k, nums, mp);
        
        if(!mp[nums[i] - k]  && !mp[nums[i] + k]) {
            mp[nums[i]]++;
            backtrack(i+1, k , nums, mp);
            
            // remove it after use
            mp[nums[i]]--;
        }
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        result = 0;
        n = nums.size();
        
        vector<int> curr;
        unordered_map<int, int> mp;
        backtrack(0 , k , nums, mp);
        
        return result - 1;
    }
};