class Solution {
private:

    bool isViable(int cap , int& n, vector<int> &quantities) {
        int required = 0;

        for(int i = 0; i < quantities.size(); i++) {
            required += (quantities[i] + cap - 1) / cap;  // Integer division that mimics ceiling
        }

        return required <= n;
    }

    
    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int i=1 , j= *max_element(quantities.begin() , quantities.end());
        
        int ans = INT_MAX;
        
        while(i <= j) {
            int mid = i + (j-i)/2 ;
            
            if(isViable(mid , n , quantities)) {
                ans = min(ans , mid);
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        
        return ans;
    }
};