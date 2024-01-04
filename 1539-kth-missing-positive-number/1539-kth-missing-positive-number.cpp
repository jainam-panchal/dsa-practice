class Solution {

public:
    int findKthPositive(vector<int>& nums, int k) {
        
        // Binary Search : O(logn)
        // Strivers ftw
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int missingNumbers = nums[mid] - (mid + 1);
            if(missingNumbers < k)
                start = mid + 1; 
            else
                end = mid - 1;

        }
        
        // return k + end + 1; 
        return start + k;
    }
};


//         // BRUTEFORCE: O(N)
//         // https://www.youtube.com/watch?v=BltzCxN1vRc
        
//         int num = 1;
//         int i=0;
//         int n=nums.size();
        
//         while(i < n && k > 0) {
//             // not missing
//             if(nums[i] == num) {
//                 i++;
//             }
//             // missing
//             else {
//                 k--;
//             }
//             num++;
//         }
        
//         // edge case
//         // {1,2,3}, k=2
//         while(k--) {
//             num++;
//         }
        
//         return num-1;