class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
     
        // BRUTEFORCE METHOD - O(1)
        vector<int> possibleAns = {12, 23, 34, 45, 56, 67, 78, 89,
                              123, 234, 345, 456, 567, 678, 789,
                              1234, 2345, 3456, 4567, 5678, 6789,
                              12345, 23456, 34567, 45678, 56789,
                              123456, 234567, 345678, 456789,
                              1234567, 2345678, 3456789,
                              12345678, 23456789,
                              123456789
        };
        
        vector<int> ans;
        for(int i=0 ; i<possibleAns.size() ; i++) {
            
            if(possibleAns[i] >= low && possibleAns[i] <= high) {
                ans.push_back(possibleAns[i]);
            }
            
            if(possibleAns[i] > high) {
                break;
            }
            
        }
        
        return ans;
        
             
        
//         // Simple BFS Method - O(n). O(n)
//         queue<int> q;
//         vector<int> ans;
        
//         // initial state
//         // not including 9 because it won't give us possible val if we put it first
//         for(int i=1 ; i<9 ; i++) {
//             q.push(i);
//         }
        
//         while(!q.empty()) {
//             int ele = q.front();
//             q.pop();
            
//             // just to optimize
//             if(ele > high) {
//                 break;
//             }
            
//             // if valid element, add it to ans 
//             if(ele >= low &&  ele <= high) {
//                 ans.push_back(ele);
//             }
            
//             // else get the last element and increment on. then append it
//             int last_digit = ele % 10;
//             if(last_digit + 1 <= 9) {
//                 q.push(ele*10 + (last_digit+1));
//             }
            
//         }
        
        
//         return ans;
    }
};