class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        vector<int> prefix_xor(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix_xor[i + 1] = prefix_xor[i] ^ arr[i];
        }
        
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k <= n; ++k) {
                if (prefix_xor[i] == prefix_xor[k]) {
                    count += (k - i - 1);
                }
            }
        }
        
        return count;
    }
};
