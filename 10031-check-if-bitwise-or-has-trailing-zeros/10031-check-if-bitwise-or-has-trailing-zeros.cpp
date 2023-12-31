class Solution {
private:
    bool checkTrailing(int n)
    {
        bitset<64> bit;

        bit |= n;

        int count = 0;

        for (int i = 0; i < 64; i++)
        {
            if (bit[i] == 0)
                count++;
            else
                break;
        }

        return count >= 1;
    }
    
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int totalChecks = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (totalChecks >= 2)
                return true;
            if (checkTrailing(nums[i]))
                totalChecks++;
        }

        if (totalChecks >= 2)
            return true;
        return false;
    }
};