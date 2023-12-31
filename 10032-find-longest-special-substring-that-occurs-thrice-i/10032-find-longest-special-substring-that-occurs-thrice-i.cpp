class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> subCounts;

        // Generate all substring and store their counts
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + 1; j <= s.length(); j++)
            {
                string subString = s.substr(i, j - i);
                subCounts[subString]++;
            }
        }

        int maxLen = -1;

        // For each pair
        for (auto &pair : subCounts)
        {
            string subString = pair.first;
            int count = pair.second;

            // if the count >= 3
            if (count >= 3)
            {
                // check if all the char are same?
                bool allCharSame = true;
                for (int i = 0; i < subString.length(); i++)
                {
                    if (subString[i] != subString[0])
                    {
                        allCharSame = false;
                        break;
                    }
                }
                // if yes then update maxLen
                if (allCharSame)
                {
                    maxLen = max(maxLen, (int)subString.length());
                }
            }
        }

        return maxLen;
    }
};