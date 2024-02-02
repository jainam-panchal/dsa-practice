class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
        
        // Simple BFS Method
        queue<int> q;
        vector<int> ans;
        
        // initial state
        // not including 9 because it won't give us possible val if we put it first
        for(int i=1 ; i<9 ; i++) {
            q.push(i);
        }
        
        while(!q.empty()) {
            int ele = q.front();
            q.pop();
            
            // just to optimize
            if(ele > high) {
                break;
            }
            
            // if valid element, add it to ans 
            if(ele >= low &&  ele <= high) {
                ans.push_back(ele);
            }
            
            // else get the last element and increment on. then append it
            int last_digit = ele % 10;
            if(last_digit + 1 <= 9) {
                q.push(ele*10 + (last_digit+1));
            }
            
        }
        
        
        return ans;
    }
};