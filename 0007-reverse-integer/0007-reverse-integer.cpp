class Solution {
public:
    int reverse(int x) {
        
        int rev = 0;
        int max = INT_MAX/10;
        int min = INT_MIN/10;
        
        while(x != 0) {
            int rem = x%10;
            if(rev > max || rev <min)
                return 0;
            rev = (rev*10) + rem;
            x/=10;
        }

        return rev;
    }
    
};