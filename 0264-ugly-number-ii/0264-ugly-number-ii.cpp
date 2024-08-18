class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1; // First ugly number is 1
        
        int i2 = 0, i3 = 0, i5 = 0; // Indices for 2, 3, and 5
        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;
        int nextUglyNumber = 1;
        
        for(int i = 1; i < n; i++) {
            // Find the next ugly number
            nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;
            
            // Update the respective index and next multiple of 2, 3, or 5
            if(nextUglyNumber == nextMultipleOf2) {
                i2++;
                nextMultipleOf2 = uglyNumbers[i2] * 2;
                cout << i2 << " " << uglyNumbers[i2] << " * 2" << endl;
            }
            if(nextUglyNumber == nextMultipleOf3) {
                i3++;
                nextMultipleOf3 = uglyNumbers[i3] * 3;
                cout << i3 << " " << uglyNumbers[i3] << " * 3" << endl;
            }
            if(nextUglyNumber == nextMultipleOf5) {
                i5++;
                nextMultipleOf5 = uglyNumbers[i5] * 5;
                cout << i5 << " " << uglyNumbers[i5] << " * 5 " << endl;
            }
        }
        
        return nextUglyNumber; // nth ugly number
    }
};
