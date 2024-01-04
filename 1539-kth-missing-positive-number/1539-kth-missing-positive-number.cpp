class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = k;
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i] <= n) n++;
            else return n;
        }
        return n;
    }
};