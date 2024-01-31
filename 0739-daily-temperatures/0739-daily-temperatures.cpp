class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        vector<int> ans(t.size());
        stack<int> st;
            
        for(int i=t.size()-1 ; i>=0 ; i--) {
            
            // find the perf position
            while(!st.empty() && t[i] >= t[st.top()])
                st.pop();
            
            // no stack element :/
            if(st.empty()) {
                ans[i] = 0;
            }
            // we got the top
            else {
                ans[i] = st.top()-i;
            }
            
            // push the curr element
            st.push(i);
        }
        
        return ans;
    }
};