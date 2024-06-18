class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> profAndDiff;
        
        for(int i = 0; i < difficulty.size(); i++) {
            profAndDiff.push_back({difficulty[i], profit[i]});
        }
        
        sort(profAndDiff.begin(), profAndDiff.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0, best = 0;
        int onProfit = 0;
        int n = worker.size();
        
        for(int i = 0; i < n; i++) {
            while(onProfit < profAndDiff.size() && worker[i] >= profAndDiff[onProfit].first) {
                best = max(best, profAndDiff[onProfit].second);
                onProfit++;
            }
            maxProfit += best;
        }
        
        return maxProfit;

    }
};