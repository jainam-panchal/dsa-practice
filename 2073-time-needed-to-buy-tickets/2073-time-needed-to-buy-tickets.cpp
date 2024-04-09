class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> q;
        for(int i=0 ; i<tickets.size() ; i++) {
            q.push(i);
        }
        
        while(!q.empty()) {
            time++;
            
            // take out the first index
            int temp = q.front();
            q.pop();
            
            
            // decrement the val
            tickets[temp]--;
            
            // if valid pos gets zero, return
            if(temp == k && tickets[temp] == 0) {
                return time;
            }
            
            // if need more tickets, just come again
            if(tickets[temp] > 0) 
                q.push(temp);
        }
        
        return time;
    }
};