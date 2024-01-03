class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int previous = 0;
        int ans = 0;
        
        for (int i = 0; i < bank.size(); i++)
        {
            string str = bank[i];
            int currCount = 0;
            
            // count number of 1's in each row
            for (char ch : str)
            {
                if ((ch - '0') == 1)
                    currCount++;
            }
            
            // calculate the answer
            if(currCount != 0) {
                ans += previous * currCount;
                previous = currCount;
            }
            
        }
        
        return ans;
    }
};