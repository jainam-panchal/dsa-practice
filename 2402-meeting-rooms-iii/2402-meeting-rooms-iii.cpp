class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        vector<long long> lastAvailableAt(n, 0);
        vector<int> timesUsed(n,0);
        
        for(auto meeting : meetings) {
            
            int start = meeting[0];
            int end = meeting[1];
            bool found = false;
            
            int earlyEndRoom = 0;
            long long earlyEndRoomTime = LLONG_MAX;
            
            // if we can find an empty room
            for(int room=0 ; room<n ; room++) {
                if(lastAvailableAt[room] <= start) {
                    lastAvailableAt[room] = end;
                    timesUsed[room]++;
                    found = true;
                    break;
                }
                
                if(earlyEndRoomTime > lastAvailableAt[room]) {
                    earlyEndRoomTime = lastAvailableAt[room];
                    earlyEndRoom = room;
                }
            }
            
            // assign which will be available first
            if(!found) {
                lastAvailableAt[earlyEndRoom] += (end-start);
                timesUsed[earlyEndRoom]++;
            }
            
        }
        
        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(timesUsed[room] > maxUse) {
                maxUse = timesUsed[room];
                resultRoom = room;
            }
        }

        return resultRoom;

    }
};