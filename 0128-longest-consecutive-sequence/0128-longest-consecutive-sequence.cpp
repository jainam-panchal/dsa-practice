class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        // bruteforce 
        
        sort(nums.begin() , nums.end());
        
        int maxi = 1;
        int curr = 1;
        
        for(int i=1 ; i<nums.size() ; i++) {
            
            if(nums[i-1] == nums[i]) continue;
            else if((nums[i-1] + 1) == nums[i]) {
                curr++;
                maxi = max(maxi , curr);
            } else {
                cout << "reset at " << i << endl;
                curr = 1;
            }
        }
        
        return maxi;
    }
};