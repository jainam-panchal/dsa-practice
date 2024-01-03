class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<vector<int>> matrix;
        vector<int> count;
        
        // count number of 1's in each row
        for (int i = 0; i < bank.size(); i++)
        {
            string str = bank[i];
            int currCount = 0;
            for (char ch : str)
            {
                if ((ch - '0') == 1)
                    currCount++;
            }
            count.push_back(currCount);
        }
        
        // find the ans
        int ans = 0;
        bool selectMode = true;
        int mul = 1;
        for (int i = 0; i < count.size(); i++)
        {
            if (selectMode)
            {
                if (count[i] != 0)
                {
                    mul = count[i];
                    selectMode = false;
                }
            }
            else
            {
                if (count[i] != 0)
                {
                    ans += mul * count[i];
                    mul = count[i];
                }
            }
        }

        return ans;
    }
};