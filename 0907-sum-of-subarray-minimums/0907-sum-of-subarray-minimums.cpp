#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long result = 0;
        stack<int> st;

        // Arrays to store the leftmost and rightmost smaller elements for each element
        vector<int> leftSmaller(n, -1);
        vector<int> rightSmaller(n, n);

        // Calculate leftSmaller array using a stack
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                rightSmaller[st.top()] = i;
                st.pop();
            }
            leftSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Calculate the sum    
        for (int i = 0; i < n; ++i) {
            long long leftCount = i - leftSmaller[i];
            long long rightCount = rightSmaller[i] - i;
            result = (result + (leftCount * rightCount % MOD) * arr[i]) % MOD;
        }

        return (int)result;
    }
};
