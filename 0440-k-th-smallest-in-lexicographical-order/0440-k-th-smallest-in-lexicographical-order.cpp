class Solution {
private:
    int count (long i , long j , int n) {
        int steps = 0;
        
        while(i <= n) {
            steps += min((long)(n+1) , j) - i;
            // steps += min((n + 1), j) - i;

            i *= 10; j *= 10;
        }
        
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        k--;
        int curr = 1;
        
        
        while(k > 0) {
            int steps = count(curr , curr+1 , n);
            if(steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10; k--;
            }
        }
        
        return curr;
    }
};