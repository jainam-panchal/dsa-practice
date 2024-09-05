class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int roll_sum = 0;
        for(auto i : rolls) {
            roll_sum += i;
        }
        
        int m = rolls.size();
        vector<int> ans;
        
        int total_sum = mean * (m + n);
        int missing_sum = total_sum - roll_sum;
        
        if(missing_sum > 6*n || missing_sum < n) return ans;
        
        while(n) {
            int dice = min(6 , missing_sum - n + 1);
            ans.push_back(dice);
            missing_sum -= dice;
            n--;
        }
        
        return ans;
    }
};