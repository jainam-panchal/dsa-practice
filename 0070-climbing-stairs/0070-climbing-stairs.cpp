class Solution {
private:
    int f(vector<int> &arr, int n) {
        if(n <= 1) {
            return 1;
        }
        if(arr[n] == -1) {
            arr[n] = f(arr,n-1) + f(arr,n-2);
            return arr[n];
        }
        else {
            return arr[n];
        }
    }
public:
    int climbStairs(int n) {
        vector<int> arr(n+1, -1);
        return f(arr,n);
    }
};