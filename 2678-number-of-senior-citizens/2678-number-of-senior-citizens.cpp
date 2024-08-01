class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int count = 0;
        for(auto curr : details) {
            int n = curr.size();
            if(stoi(curr.substr(11, 2)) > 60) {
                count++;
            }
        } 
        return count;
    }
};