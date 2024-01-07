class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        
        // basically store how many subsequences we got from j=0 to j=i with difference
        // and find the final ans        
        // https://www.youtube.com/watch?v=cau0JE1q_ZA
        
        // array of map : difference and freq

        unordered_map<long, int> map[n];
        int result = 0;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j=0 ; j < i ; j++) {
                
                // find the difference
                long diff = (long)nums[i] - nums[j];
                
                auto it = map[j].find(diff);
                
                // check the prev values, if iterator is at the end put 0, or put the value
                int count_at_j = (it == end(map[j])) ? 0 : it->second;

                // update the current values
                map[i][diff] += count_at_j + 1;
                
                //  where count_at_j is the freq of the prev diff. So we're only updating result when we have already encountered it previously. So two pairs, one common = three numbers
                result += count_at_j;
                    
            }
        }
        
        return result;
    }
};