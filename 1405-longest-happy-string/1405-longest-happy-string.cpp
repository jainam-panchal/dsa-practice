class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string ans = "";  
        
        while (!pq.empty()) {
            pair<int, char> temp = pq.top();
            pq.pop();
            
           
            if (ans.size() < 2 || ans[ans.size() - 1] != temp.second || ans[ans.size() - 2] != temp.second) {
                ans += temp.second;
                temp.first -= 1;
            } else {
                
                if (pq.empty()) {
                    return ans;
                }
                pair<int, char> temp2 = pq.top();
                pq.pop();
                ans += temp2.second;
                temp2.first -= 1;
                
                if (temp2.first > 0) {
                    pq.push(temp2); 
                }
            }
            
           
            if (temp.first > 0) {
                pq.push(temp);
            }
        }
        
        return ans;
    }
};
