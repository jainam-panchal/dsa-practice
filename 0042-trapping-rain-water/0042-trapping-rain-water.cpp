class Solution {
public:
    int trap(vector<int>& arr) {
        
        // Optimal approach - Sliding window
        int n = arr.size();
        
        int leftMax = 0; int rightMax = 0;
        int left = 0; int right = n-1;
        
        int waterTrapped = 0;
        while(left <= right) {
            if(arr[left] <= arr[right]) {
                if(arr[left] >= leftMax) leftMax = arr[left];
                else waterTrapped += leftMax - arr[left];
                left++;
            }
            else {
                if(arr[right] >= rightMax) rightMax = arr[right];
                else waterTrapped += rightMax - arr[right];
                right--;
            }
        }
        
        return waterTrapped;
    }
};


// This approach is Better approch

    // Time Complexity: O(3*N) as we are traversing through the array only once. 
    // And O(2*N) for computing prefix and suffix array.

    // Space Complexity: O(N)+O(N) for prefix and suffix arrays.

    // long long left[n] = {0};
    // long long right[n] = {0};

    // left[0] = arr[0];
    // right[n-1] = arr[n-1];

    // for(int i=1 ; i<n ; i++) {
    //     left[i] = max(left[i-1] , arr[i]);
    // }
    // for(int j=n-2; j>=0 ; j--) {
    //     right[j] = max(right[j+1], arr[j]);
    // }

    // long long waterTrapped = 0;
    // for(int i=0 ; i<n ; i++) {
    //     waterTrapped = waterTrapped + (min(left[i], right[i]) - arr[i]);
    // }

    // return waterTrapped;
