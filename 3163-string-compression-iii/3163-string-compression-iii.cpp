class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans;
        
        int i=0;
        
        while(i < n) {
            char curr = word[i];
            
            int j = i+1;
            int count = 1;
            while(count < 9 && j < n && curr == word[j]) {
                j++; count++;
            }
            
            ans += to_string(count) + curr;
            
            i += count;
        }
        
        return ans;
    }
};