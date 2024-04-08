class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;
        for(auto stud : students) {
            q.push(stud);
        }
        
        stack<int> st;
        for(int i=sandwiches.size()-1 ; i>=0 ; --i) {
            st.push(sandwiches[i]);
        }
        
        
        int count = 0;
        while(!st.empty() && count<q.size()) {
            if(st.top() != q.front()) {
                q.push(q.front());
                q.pop();
                count++;
            }
            else {
                q.pop();
                st.pop();
                count=0;
            }
        }
        
        return st.size();
    }
};