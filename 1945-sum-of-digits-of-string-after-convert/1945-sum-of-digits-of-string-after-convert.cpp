class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        
        for(auto i : s) {
            str += to_string(i - 'a' + 1);
        }
        
        // cout << str;
        
        int sum = 0;
        while(k) {
            int currSum = 0;
            for(auto i : str) {
                currSum += i - '0';
            }            
            str = to_string(currSum);
            k--;
        }
        
        return stoi(str);
    }
};