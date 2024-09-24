class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix;
         
        for(auto val : arr1) {
            while(!prefix.count(val) && val > 0) {
                prefix.insert(val);
                val /= 10;
            }
        }
        
        int ans = 0;
        
        
        for(auto val : arr2) {
            while(!prefix.count(val) && val > 0) val /= 10;
            if(val > 0) ans = max(ans , static_cast<int>(log10(val) +1));
        }
        
        return ans;
    }
    
    
};