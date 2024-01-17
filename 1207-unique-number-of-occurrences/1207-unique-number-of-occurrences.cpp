class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hash;
        
        // find all occurence
        for(auto val : arr) {
            if(hash.find(val) == hash.end()) {
                hash[val] = 1;
            }
            else {
                hash[val]++;
            }
        }
        
        set<int> st;
        for(auto i = hash.begin() ; i != hash.end() ; i++) {
            // std::pair<iterator,bool>
            
            // insert method returns true if it's inserted. 
            // so if the item already exist it returns false 
            // we execute the if block if it's false
            
            if(!st.insert(i->second).second) {
                return false;   
            }
        }
        
        return true;
    }
};