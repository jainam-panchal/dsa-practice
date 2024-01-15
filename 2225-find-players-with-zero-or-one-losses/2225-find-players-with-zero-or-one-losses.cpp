class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        // to keep track of looses
        unordered_map<int,int> map;
        
        // to keep track of all encountered players
        set<int> players;
        
        // iterate all matches
        for(int i=0 ; i<matches.size() ; i++) {
            int winner = matches[i][0];
            int looser = matches[i][1];
            
            // if it's player's first loose
            if(map.find(looser) == map.end()) {
                map[looser] = 1;
            }
            // already been loosing
            else {
                map[looser]++;
            }
            
            // keep track of players
            players.insert(winner);
            players.insert(looser);
            
        }
        
        vector<int> noLoose;
        vector<int> oneLoose;

        for(auto it = players.begin() ; it != players.end() ; it++) {
            
            // if the player is not found in the Looser's map
            if(map.find(*it) == map.end()) {
                // SIGMA - NO LOOSE - HEHEHE
                noLoose.push_back(*it);
            }
            else {
                // BETA MALE
                if(map[*it] == 1) {
                    oneLoose.push_back(*it);
                }
            }
        }
        
        return {noLoose, oneLoose};
    }
};