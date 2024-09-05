class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        

        int currDir = 0 , maxi = 0;
        pair<int, int> currPos = {0 , 0};

        vector<pair<int, int>> directions = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};

        unordered_set<string> st;
        for(vector<int> &ob : obstacles) {
            string temp = to_string(ob[0]) + "_" + to_string(ob[1]);
            st.insert(temp);
        }

        for(auto com : commands) {
            if(com == -1) {
                currDir = ( currDir + 1 ) % 4;
                continue;
            } else if(com == -2) {
                currDir = (currDir + 3) % 4;
                continue;
            } else {
                int currX = currPos.first;
                int currY = currPos.second;

                int dirX = directions[currDir].first;
                int dirY = directions[currDir].second;

                int moves = com;
                while(moves) {
                    currX += dirX * 1;
                    currY += dirY * 1;

                    string position = to_string(currX) + "_" + to_string(currY);
                    if(st.find(position) != st.end()) {
                        break;
                    }
                    moves--;
                    currPos = {currX , currY};
                }
            }

            maxi = max(maxi ,(currPos.first * currPos.first + currPos.second * currPos.second));
        }

        return maxi;
    }
};