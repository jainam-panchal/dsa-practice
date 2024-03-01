class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOnes = 0;
        
        
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == '1') countOnes++;
        }
        
        int countZeros = s.size()-countOnes;
        
        string ans = "";
        // put leading ones and save last one for the last
        for(int i=0 ; i<countOnes-1 ; i++) {
            ans += '1';
        }
        
        for(int i=0 ; i<countZeros ; i++) {
            ans += '0';
        }
        
        return ans + '1';
    }
};