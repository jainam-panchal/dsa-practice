class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream str1(s1) , str2(s2);
        
        string token;
        vector<string> v1 , v2 , ans;
        char delimiter = ' ';

        unordered_map<string , int> mp1 , mp2;
        
        while(getline(str1 , token , delimiter)) {
            mp1[token]++;
        }
        
        while(getline(str2 , token , delimiter)) {
            mp2[token]++;
        }
        
        for(auto ele : mp1) {
            string str = ele.first;
            int appeared = ele.second;
            
            if(appeared == 1 && mp2.find(str) == mp2.end()) {
                ans.push_back(str);
            }
        }
        
        for(auto ele : mp2) {
            string str = ele.first;
            int appeared = ele.second;
            
            if(appeared == 1 && mp1.find(str) == mp1.end()) {
                ans.push_back(str);
            }
        }
        
        return ans;
        
    }
};