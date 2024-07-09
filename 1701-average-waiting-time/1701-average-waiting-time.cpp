class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        
        long long waiting = customers[0][1];
        int curr = customers[0][0] + customers[0][1];
        
        for(int i=1 ; i<customers.size() ; i++) {
            
            int arrival = customers[i][0];
            int cooking = customers[i][1];
            
            if(arrival < curr) {
                curr += cooking;
                waiting += curr - arrival;
            } else {
                curr = arrival;
                curr += cooking;
                waiting += curr - arrival;
            }
            
        }
        
        double ans = static_cast<double>(waiting) / n;
        return ans;
    }
};