class Solution {
private:
    int findMaxi(vector<int> &bloomDay)
    {
        int maxi = bloomDay[0];
        for (int i : bloomDay)
        {
            maxi = max(i, maxi);
        }
        return maxi;
    }

    int countBq(vector<int> &timeline, int guess, int qty, int perQty)
    {
        int totalCount = 0;
        int curr = 0;
        for (int i = 0; i < timeline.size(); i++)
        {
            if (timeline[i] <= guess)
            {
                curr++;
            }
            else
            {
                curr = 0;
            }
            if (curr == perQty)
            {
                totalCount++;
                curr = 0;
            }
        }

        return totalCount;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = findMaxi(bloomDay);
        int ans = -1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            int canBeReady = countBq(bloomDay, mid, m, k);

            if (canBeReady >= m)
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};