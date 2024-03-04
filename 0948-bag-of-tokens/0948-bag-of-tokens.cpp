class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int maxScore = 0;
        
        sort(tokens.begin(), tokens.end());
        
        int i=0; int j=n-1;
        
        int score = 0;
        while(i <= j) {
            if(power >= tokens[i]) {
                score++;
                power -= tokens[i];
                i++;
                
                maxScore = max(maxScore,score);
            } else if(score >= 1) {
                score--;
                power += tokens[j];
                j--;
            }
            else {
                return maxScore;
            }
            
        }
        
        return maxScore;
    }
};