class Solution {
public:
    int evalRPN(vector<string>& arr) {
        
        stack<int> st;
        
        for(int i=0 ; i<arr.size() ; i++) {
            
            // check for operators
            if(arr[i] != "+" && arr[i] != "-" && arr[i] != "*" && arr[i] != "/") {
                st.push(stoi(arr[i]));
                continue;
            }
            
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            
            if(arr[i] == "+") st.push(first + second);
            else if(arr[i] == "-") st.push(first - second);
            else if(arr[i] == "*") st.push(first * second);
            else if(arr[i] == "/") st.push(first / second);
            
        }
        
        return st.top();
    }
};