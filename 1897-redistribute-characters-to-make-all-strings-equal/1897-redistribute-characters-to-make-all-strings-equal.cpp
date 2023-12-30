class Solution {
public:
    bool makeEqual(vector<string>& words) {
          
        // Approach 1 : O(n * k) , O(1)
        
        // Simply Just Count all frequency and check if we can allocate equally to every word?
        // if not then return false
        
        unordered_map<char, int> hash;
        for(string word : words) {
            for(char c : word) {
                hash[c]++;
            }
        }
        
            int n = words.size();
            for(auto& [key, val] : hash) {
                if(val % n != 0) {
                    return false;
                }
            }
            
            return true;
    }
};