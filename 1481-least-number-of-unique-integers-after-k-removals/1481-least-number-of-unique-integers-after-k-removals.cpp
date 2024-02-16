class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto it=freq.begin() ; it != freq.end() ; it++) {
            pq.push(it->second);
        }
        
        while(!pq.empty()) {
            k -= pq.top();
            if(k < 0) 
                return pq.size();            
            pq.pop();

        }
        
        return 0;
        
        
    }
};