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
        for(int i=0 ; i < n ; i++) {
            if(st.empty()) {
                leftSmaller[i] = -1;
                st.push(i);
            }
            else {
                while(!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                if(st.empty()) leftSmaller[i] = -1;
                else leftSmaller[i] = st.top();
                st.push(i);
            }
        }
        
        while (!st.empty()) st.pop();  // Clear the stack

        // Calculate rightSmaller array using a stack
        for(int j=arr.size()-1 ; j >= 0 ; j--) {
            if(st.empty()) {
                rightSmaller[j] = n;
                st.push(j);
            }
            else {
                while(!st.empty() && arr[st.top()] > arr[j]) {
                    st.pop();
                }
                if(st.empty()) rightSmaller[j] = n;
                else rightSmaller[j] = st.top();
                st.push(j);
            }
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