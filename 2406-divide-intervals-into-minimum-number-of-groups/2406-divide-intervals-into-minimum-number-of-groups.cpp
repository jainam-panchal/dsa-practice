class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

       
        sort(intervals.begin() , intervals.end());
        
        // min heap
        priority_queue<int , vector<int> , greater<int>> minheap;
        
        for(auto &inteval : intervals) {
            
            int start = inteval[0] , end = inteval[1];
            
            if(!minheap.empty() && minheap.top() < start) {
                minheap.pop();
            }
            
            minheap.push(end);
        }
        
        return minheap.size();
    }
};