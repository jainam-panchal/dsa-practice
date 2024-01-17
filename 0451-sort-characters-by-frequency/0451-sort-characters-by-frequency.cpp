class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        
        // iterate over the string
        // calculate the freq
        for(auto ch : s) {
            if(mp.find(ch) == mp.end())
                mp.insert({ch, 1});
            else
                mp[ch]++;
        }
        
        // insert all freq into priority queue
        priority_queue<pair<int,char>> q;
        for(auto it : mp) {
            q.push(make_pair(it.second, it.first));
        }
        
        // pop everything from the queue
        string ans = "";
        while(!q.empty()) {
            
            // get the top most value
            char ch = q.top().second;
            int freq = q.top().first;
            
            // insert it into the string
            for(int i=0 ; i<freq ; i++) {
                ans += ch;
            }
            
            // pop the item
            q.pop();
        }
        
        return ans;
    }
};