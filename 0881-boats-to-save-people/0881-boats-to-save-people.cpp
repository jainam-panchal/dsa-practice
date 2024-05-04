class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // GREEDY SOLUTION
        
        int totalBoats = 0;
        sort(people.begin() , people.end());
        
        int i=0, j=people.size()-1;
        
        while(i <= j) {
            
            // heaviest and lightest person can share, inc i
            if(people[i] + people[j] <= limit) {
                i++;
            }
            
            // boat is used for heaviest person so next heavy, dec j
            j--;
            
            totalBoats++;
        }
        
        return totalBoats;
    }
};