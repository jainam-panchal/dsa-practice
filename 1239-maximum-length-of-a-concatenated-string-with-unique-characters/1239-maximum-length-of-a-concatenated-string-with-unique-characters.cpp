class Solution {
private:
    bool hasDuplicate(string s1, string s2) {
        vector<int> hash(26, 0);
        
        for(char c : s1) {
            if(hash[c - 'a'] > 0)
                return true;
            hash[c - 'a']++;
        }
        
        for(char c : s2) {
            if(hash[c - 'a'] > 0)
                return true;
        }
        
        return false;
    }
    
    int solve(int i, vector<string>& arr, string temp, int n) {
        // base case
        if(i > n) return temp.length();
        
        int incl = 0;
        int excl = 0;

        // if we find any duplicates, only one option - exclude
        if(hasDuplicate(arr[i], temp)) {
            excl = solve(i+1, arr, temp, n);
        }
        // if we don't find any duplicats
        else {
            incl = solve(i+1, arr, temp + arr[i], n);
            excl = solve(i+1, arr, temp, n);
        }
        
        return max(incl,excl);
    }
    
public:
    int maxLength(vector<string>& arr) {
        
        int i = 0;
        int n = arr.size();
        
        string temp = "";
        
        return solve(i, arr, temp, n-1);
    }
};