class Solution {
public:
    long  int mySqrt(int x) {
        int start = 0;
        int end   = x;
        
        long  int ans = -1;
        long  int mid = start + (end - start) / 2;
        long  int square;
        
        while (start <= end) {
            square = mid * mid;
            if(square == x){
                return mid;
            }
            else if(square < x){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start) / 2; 
        }
        return ans;
    }
};