class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n=nums.size();
        deque<char> dq;
        dq.push_back(nums[0]);
        
        // it should be increasing
        for(int i = 1; i < n; i++) {
            
            // if not inc
            while (!dq.empty() && dq.back() > nums[i] && k > 0) {
                dq.pop_back();
                k--;
            }
            
            // just add
            dq.push_back(nums[i]);
        }
        
        // if we didn't delete any digit
         while (k > 0 && !dq.empty()) {
            dq.pop_back();
            k--;
        }
        
        // remove leading zeros
        while (!dq.empty() && dq.front() == '0') {
            dq.pop_front();
        }
        
        string ans;
        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
        }
        
        return ans.length() == 0 ? "0" : ans;
    }
};