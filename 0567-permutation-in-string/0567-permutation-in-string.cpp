class Solution {
private:
    bool compare(int count1[26] , int count2[26]) {
        for(int i=0 ; i<26 ; i++) {
            if(count1[i] != count2[i])
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // Algo
        
        // 1. Calc hashmap for s1
        int count1[26] = {0};
        for(int i=0 ; i<s1.size() ; i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        // 2. Traverse through the first window and compare
        int count2[26] = {0};
        int i=0;
        int windowSize = s1.size();
        
        while(i < windowSize && i <s2.size()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        if ( compare(count1,count2) ) return true;
        
        // If not true then check in the rest of string
        while(i < s2.size() ) {
            int index = s2[i] - 'a';
            count2[index]++;
            
            index = s2[i-windowSize] - 'a';
            count2[index]--;
            
            i++;
            if ( compare(count1,count2) ) return true;
        }
        
        return false;
    }
};