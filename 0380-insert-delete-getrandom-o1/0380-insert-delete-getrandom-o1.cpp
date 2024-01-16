class RandomizedSet {
    set<int> rset;

public:
    RandomizedSet() {
         
    }
    
    bool insert(int val) {
        // if not present
        if(rset.find(val) == rset.end()) {
            rset.insert(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    bool remove(int val) {
        // if present
        if(rset.find(val) != rset.end()) {
            // remove it and return true
            rset.erase(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    int getRandom() {
        
        // generate a random index within the set size
        size_t rIndex = rand() % rset.size();
        
        // move to the random position
        auto it = next(rset.begin(), rIndex);
        
        return *it;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */