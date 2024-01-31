class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        vector<int> ans(arr.size());
        stack<int> st;
        int n = arr.size();
        
        for(int i=n-1 ; i >= 0 ; i--) {
            
            // try to find the greater ele in stack
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            
            // two poss -> we have an element or zero
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top() - i;
            
            
            // add the curr element
            st.push(i);
        }
        
        return ans;
    }
};