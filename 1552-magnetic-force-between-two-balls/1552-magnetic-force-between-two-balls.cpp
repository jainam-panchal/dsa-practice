class Solution {
private:
    bool isPossible(vector<int>& position, int m, int dist) {
        
        int prevInd = position[0];
        int placedBalls = 1;
        
        for(int i=0 ; i<position.size() ; i++) {
            int ind = position[i];
            if(ind - prevInd >= dist) {
                placedBalls++;
                prevInd = ind;
            }
            
            if(placedBalls >= m) {
                break;
            }
        }
        
        if(placedBalls == m)
            return true;
        
        return false;
        
    }
public:
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin() , position.end());
        
        int ans = 0;
        int start = 0;
        int end = *max_element(position.begin() , position.end());
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(isPossible(position, m , mid)) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }    
        }
        
        return ans;
    }
};