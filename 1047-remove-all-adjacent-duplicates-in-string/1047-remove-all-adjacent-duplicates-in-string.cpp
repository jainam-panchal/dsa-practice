class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> charStack;
        string ans = "";
        
        // if top 2 elements are same then pop the last, else push
        for(int i=0 ; i<s.size() ; i++) {
            if( !charStack.empty() && charStack.top() == s[i] ) {
                charStack.pop();
            }
            else {
                charStack.push(s[i]);
            }
        }
        
        // pulling back char from stack
        while(!charStack.empty()) {
            char temp = charStack.top();
            charStack.pop();
            ans.push_back(temp);
        }   
        
        // since stack gives ans in reverse order
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};