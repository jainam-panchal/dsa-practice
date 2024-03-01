class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOnes = 0;
        
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == '1') countOnes++;
        }
        int countZeros = s.size()-countOnes;
        
        return string(countOnes-1, '1') + string(countZeros,'0') + '1';
    }
};