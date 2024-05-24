class Solution {
private:
    int n;
    int maxi;
    
    void backtrack(int idx, int curr, vector<string> &words, unordered_map<char, int> &mp, vector<int> &score) {
        if(idx >= n) {
            maxi = max(maxi, curr);
            return;
        }
        
        backtrack(idx+1 , curr , words, mp, score);
        
        // check if we can include this or not
        bool canWe = true;
        vector<char> usedChars;
        for(auto val : words[idx]) {
            if(mp[val] > 0) {
                mp[val]--;
                usedChars.push_back(val);
            }
            else {
                canWe = false;
                break;
            }
        }
        
        if(canWe) {
            // add score of each character to the elementScore
            int elementScore = 0;
            for(auto val : words[idx]) {
                int i = val - 'a';
                elementScore += score[i];
            }
            
            curr += elementScore;
            backtrack(idx+1, curr, words , mp, score);
            
            // now restore the map
            for (auto val : words[idx]) {
                mp[val]++;
            }
        }
        else {
            for(auto val : usedChars) {
                mp[val]++;
            }
        } 
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        maxi = INT_MIN;
        n = words.size();
        
        unordered_map<char, int> mp;
        for(int i=0 ; i<letters.size() ; i++) {
            mp[letters[i]]++;
        }
        
        backtrack(0, 0, words, mp, score);
        return maxi;
        
    }
};