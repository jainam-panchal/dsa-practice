class Solution {
public:
    typedef pair<int, int> P;
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        // to sort everything acrdng to time
        map<int, vector<P>> timeMeetings;
        for(auto& meeting : meetings) {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int time = meeting[2];
            
            timeMeetings[time].push_back({p1,p2});
        }
        
        vector<int> doesKnow(n, 0);
        doesKnow[0] = 1;
        doesKnow[firstPerson] = 1;
        
        for(auto it : timeMeetings) {
            int t = it.first;
            auto meets = it.second;
            
            // create a graph on each time
            // for edge case : multiple meetings at same time
            unordered_map<int, vector<int>> adj;
            unordered_set<int> alreadyAdded;
            queue<int> que;
            
            for(auto& [person1, person2] : meets) {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);
                
                if(doesKnow[person1] && alreadyAdded.find(person1) == alreadyAdded.end()) {
                    que.push(person1);
                    alreadyAdded.insert(person1);
                }
                
                if(doesKnow[person2] && alreadyAdded.find(person2) == alreadyAdded.end()) {
                    que.push(person2);
                    alreadyAdded.insert(person2);
                }
            }
            
            while(!que.empty()) {
                int p = que.front(); que.pop();
                for(auto &nextPerson : adj[p]) {
                    if(!doesKnow[nextPerson]) {
                        doesKnow[nextPerson] = 1;
                        que.push(nextPerson);
                    }
                }
            }
        }
        
        vector<int> ans;
        for(int i=0 ; i<n ; i++) {
            if(doesKnow[i] == 1) ans.push_back(i);
        }
        
        return ans;
    }
};