class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        // for negative powers, we put the base in the deno and make it abs
        if(n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        
        if(n % 2 == 0) return myPow(x * x, n / 2);
        else return x * myPow(x, n - 1);
    }
};