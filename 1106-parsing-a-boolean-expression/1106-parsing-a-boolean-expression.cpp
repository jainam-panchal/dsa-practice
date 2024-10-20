class Solution {

private:
    void helper(stack<char> &optr , stack<char> &operand) {
        int sign = operand.top() == 't' ? 1 : 0;
        operand.pop();
        
        if(optr.top() == '&') {
            while(operand.top() != '(') {
                int val = operand.top() == 't' ? 1 : 0;
                sign &= val;
                operand.pop();
            }
        }
        else if(optr.top() == '|') {
            while(operand.top() != '(') {
                int val = operand.top() == 't' ? 1 : 0;
                sign |= val;
                operand.pop();
            }
        }
        else if(optr.top() == '!') {
            sign = !sign;
        }
        
        optr.pop();
        operand.pop();  // Remove the '(' from the stack
        sign ? operand.push('t') : operand.push('f');
    }

public:
    bool parseBoolExpr(string str) {
        // Sign goes to optr, f/t,() in operand
        stack<char> optr, operand;
        
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(') {
                operand.push('(');      
            }
            else if(str[i] == '!' || str[i] == '&' || str[i] == '|') {
                optr.push(str[i]);
            }
            else if(str[i] == 't' || str[i] == 'f') {
                operand.push(str[i]);
            }
            else if(str[i] == ')') {
                helper(optr, operand);
            }
        }

        return operand.top() == 't';
    }
};
