class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int steps = 0;
        
        int n = s.size() - 1;
        while(n > 0) {
            if(((s[n] - '0') + carry) % 2 == 1) {
                steps += 2;
                carry = 1;
            } 
            else {
                steps++;
            }
            
            n--;
        }
        
        return steps + carry;
    }
};