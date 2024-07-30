class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count = 0;
        
        for(int i=0 ; i<s.size() ; i++) {
            if(!st.empty() && s[i] == 'a' && st.top() == 'b') { //'ba'
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }
        
        return count;
    }
};