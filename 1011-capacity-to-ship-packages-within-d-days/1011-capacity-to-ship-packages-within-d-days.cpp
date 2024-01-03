class Solution {
private:
    int daysTaken(vector<int> weights, int cap) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > cap)
            {
                days++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }

        return days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            maxi = max(weights[i], maxi);
            sum += weights[i];
        }

        int start = maxi;
        int end = sum;
        int ans = maxi;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int totalDays = daysTaken(weights, mid);
            if (totalDays > days)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }
};