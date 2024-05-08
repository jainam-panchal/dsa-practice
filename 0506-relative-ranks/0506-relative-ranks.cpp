class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        // to store {score , index}
        unordered_map<int, int> map;
        
        for(int i=0 ; i<score.size() ; i++) {
            map[score[i]] = i;
        }
        
        vector<string> ranks(score.size());
        sort(score.begin(), score.end(), greater<int>());
        
        for(int i=0 ; i<score.size() ; i++) {
            
            int currScore = score[i];
            int index = map[currScore];
            
            if(i==0)
                ranks[index] = "Gold Medal";
            else if(i==1)
                ranks[index] = "Silver Medal";
            else if(i==2)
                ranks[index] = "Bronze Medal";
            else
                ranks[index] = to_string(i+1);
        }
        
        return ranks;
    }
};