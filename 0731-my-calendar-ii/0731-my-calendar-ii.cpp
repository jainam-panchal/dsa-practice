class MyCalendarTwo {
private:
    map<int,int> mp;
    
    bool canBook (int cap) {
        
        int curr = 0;
        for(auto entry : mp) {
            curr += entry.second;
            if(curr > cap) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++ ; mp[end]--;
        
        if(!canBook(2)) {
            mp[start]--; mp[end]++;
            
            if(mp[start] == 0) mp.erase(start);
            if(mp[end] == 0) mp.erase(end);
            
            return false;
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */