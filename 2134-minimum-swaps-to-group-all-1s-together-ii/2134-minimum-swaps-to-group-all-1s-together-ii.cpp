class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
        for(auto num : nums) {
            if(num == 1) totalOnes++;
        }
        if(totalOnes == 0) return 0;
        
        int n = nums.size();
        
        int currentOnes = 0;
        for(int i=0 ; i<totalOnes ; i++) {
            if(nums[i] == 1) currentOnes++;
        }
        
        int maxWindow = currentOnes;
        for(int i=1 ; i<n ; i++) {
            if(nums[i-1] == 1) currentOnes--;
            if(nums[(i+totalOnes-1) % n] == 1) currentOnes++;
            
            cout << currentOnes << " " << maxWindow << endl;
            maxWindow = max(maxWindow, currentOnes);
        }
        
        cout << totalOnes << " - " << maxWindow << endl;
        return totalOnes - maxWindow;
    }
};