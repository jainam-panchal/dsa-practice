class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // BRUTEFORCE APPROACH O(N), O(1)
        // int n = nums.size();
        // if (n == 1) return nums[0];

        // for(int i=0 ; i<n ; i++) {
        //     if(i == 0) {
        //         if(nums[i] != nums[i+1]) 
        //             return nums[i];        
        //     }
        //     else if(i == n-1) {
        //         if(nums[i] != nums[i-1])
        //             return nums[i];
        //     }
        //     else {
        //         if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
        //             return nums[i];
        //     }    
        // }
        // return -1;

        // BRUTEFORCE APPROACH O(N), O(1)
        // int n = nums.size();
        // int ans = 0;
        // for (int i=0 ; i<n ; i++) {
        //     ans = ans ^ nums[i];
        // }
        // return ans;

        // BINARY SEARCH
        int n = nums.size();

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // THE PATTERN
            // (even, odd), (even, odd) X (odd, even), (odd, even)

            // we are in the left part
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            } 
            // we are in the right part
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
