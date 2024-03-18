class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        int count = 1;
        int n = points.size();
        sort(points.begin(), points.end());
        
        vector<int> prev = points[0];
        
        for (int i = 1; i < n; i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];
            
            int prevStart = prev[0];
            int prevEnd = prev[1];
            
            // If there is an overlap, update the prev interval
            if (currStart <= prevEnd) {
                prev[0] = max(prevStart, currStart);
                prev[1] = min(prevEnd, currEnd);
            } else { // No overlap, update prev to current interval
                count++;
                prev = points[i];
            }
        }
        
        return count;
    }
};