class Solution {
public:
    string minRemoveToMakeValid(string s) {
         // remove excess closing parentheses
        string str = "";
        int op_count = 0, cls_count = 0;
        
        for(int i=0 ; i<s.size() ; i++) {
            // we always take (
            if(s[i] == '(' ) {
                op_count++;
                str += s[i];
            }
            // we only take ) if we have enough ( 
            else if(s[i] == ')') {
                if(op_count > cls_count) {
                    cls_count++;
                    str += s[i];
                }
            }
            // take all characters
            else {
                str += s[i];
            }
        }
        
        // cout << op_count << " , " << cls_count << endl;
        if(op_count == cls_count) {
            return str;
        }
        
        // just do the opposite of above
        // now we remove all excess ( and start from the back
        // suppose we have () () (
        string rev_str;
        for(int i=str.size()-1 ; i>=0 ; --i) {
            if(str[i] == '(') {
                if(op_count <= cls_count) {
                    rev_str += str[i];
                }
                else {
                    op_count--;
                }
            }
            else if(str[i] == ')') {
                rev_str += str[i];
            }
            else {
                rev_str += str[i];
            }
        }
        
        std::reverse(rev_str.begin(), rev_str.end());
        
        return rev_str;
    }
};