class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        for(int num : arr) {
            freq[num]++;
        }
        
        // possibleFreq[i] shows how many elements have i freqency
        int n = arr.size();
        vector<int> possibleFreq(n+1, 0);
        for(auto it : freq) {
            possibleFreq[it.second]++;
        }
        
        int uniqueElements = freq.size();
        
        for(int currFreq=1 ; currFreq<=n ; currFreq++) {
            int typesICanDelete = min(k/currFreq , possibleFreq[currFreq]);
            k -= (typesICanDelete * currFreq);
            uniqueElements -= typesICanDelete;
            
            if(k <= currFreq) {
                return uniqueElements;
            }
        }
        
        return 0;
        
        
    }
};