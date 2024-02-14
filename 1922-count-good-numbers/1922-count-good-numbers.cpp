class Solution {
public:
    int mod = 1e9+7;
    long long power(int base, long long pw) {
        if(pw == 0)
            return 1;
        
        long long halfPower = power(base, pw/2);
        
        if(pw % 2 == 0)
            return (halfPower * halfPower) % mod;
        
        else
            return ( ((base * halfPower) % mod) * halfPower ) % mod;
        
        
    }
    
    int countGoodNumbers(long long n) {
        // Even Indices -> 0 , 2, 4, 6, 8 = 5 in total
        // Odd Indices -> 2 , 3 , 5 , 7 = 4 in total
        
        // Total number of good digit strings would be  (5 ^ even indices) * (4 ^ odd indices)
        // Possible Values -> 5 ^ totalEvenIndices + 4 ^ totalOddIndices
        // totalEvenIndices = (n + 1)/2
        // totalOddIndices = (n/2)
        
        return  ( power(5, (n+1)/2) * power(4, n/2) ) % mod;    
    }
};