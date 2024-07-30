class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<pair<int,int>> directions = {{-1, 0}, {1 , 0} , {0 , -1} , {0 , 1}};
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
        
        vector<vector<int>> distTo(rows , vector<int>(cols, INT_MAX));
        distTo[0][0] = 0;
        
        pq.push({0,0,0});
        while(!pq.empty()) {
            auto[effort , x , y] = pq.top(); pq.pop();
            
            
            for(auto [dx , dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                
                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int current_effort = max(effort , abs(heights[x][y] - heights[nx][ny]));
                    
                    if(current_effort < distTo[nx][ny]) {
                        distTo[nx][ny] = current_effort;
                        
                        pq.push({current_effort , nx , ny});
                    }
                }
            }
        }
        
        return distTo[rows - 1][cols - 1];
    }
};