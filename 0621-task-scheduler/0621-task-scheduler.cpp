class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        
        // creating the map
         for(char task : tasks) {
            mp[task]++;
        }
        
        // adding freq to pq
        for(auto& entry : mp) {
            if(entry.second > 0)
                pq.push(entry.second);
        }
        
        while(!pq.empty()) {
            
            vector<int> temp;
            for(int i=1; i <= n+1 ; i++) {
                if(!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            
            for(int &val : temp) {
                if(val > 0) {
                    pq.push(val);
                }
            }
            
            // we used other elements too
            if(pq.empty()) {
                time += temp.size(); 
            }
            // not enough elements
            else {
                time += n+1;
            }
        }
        
        return time;
    }
};