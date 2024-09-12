class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> arr(26 , false);
        for(auto i : allowed) {
            arr[i - 'a'] = true;
        }
        
        int count = 0;
        for(auto word : words) {
            int i;
            for(i=0 ; i<word.size() ; i++) {
                if(arr[word[i] - 'a'] == false) {
                    break;
                }
            }
            // cout << i;
            if(i == word.size()) count++;
        }
        
        return count;
    }
};