class Solution {
public:
    int maximumSwap(int num) {
        vector<int> vals;
        vals.push_back(num);
        
        string nums = to_string(num);
        
        for(int i = 0; i < nums.size(); i++) {
            int ind = -1;
            char currMaxi = nums[i]; 
            
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] >= currMaxi) { 
                    ind = j;
                    currMaxi = nums[j];
                }
            }
            
            if(currMaxi > nums[i] && ind != -1) {
                swap(nums[i], nums[ind]);
                vals.push_back(stoi(nums));
                break; 
            }
        }
        
        sort(vals.begin(), vals.end(), greater<int>());
        return vals[0];
    }
};
