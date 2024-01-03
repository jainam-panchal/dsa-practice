class Solution {
private:
    int calcDivSum(vector<int>& arr, int guess) {
        int sum = 0;
        for(int val : arr) {
            int temp = ceil(static_cast<double>(val) / guess);
            sum += temp;
        }
        return sum;
    }
    
    int findMaxi(vector<int>& arr) {
        int maxi = arr[0];
        for(int val : arr) {
            maxi = max(val, maxi);
        }
        return maxi;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = findMaxi(nums);
        int ans = end;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            int sum = calcDivSum(nums, mid);
            
            if(sum > threshold) {
                start = mid + 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        
        return ans;
    }
};