class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream s1(sentence1), s2(sentence2);
        string token;
        char deli = ' ';
        
        vector<string> str1, str2;
        
        // Split both sentences into words
        while (getline(s1, token, deli)) str1.push_back(token);
        while (getline(s2, token, deli)) str2.push_back(token);
    
        int i = 0;
        
        if(str1.size() > str2.size()) swap(str1, str2);
        
        // Match words from the start
        while (i < str1.size() && str1[i] == str2[i]) {
            i++;
        }
        
        // Match words from the end
        int end1 = str1.size() - 1, end2 = str2.size() - 1;
        while (end1 >= 0 && str1[end1] == str2[end2]) {
            end1--;
            end2--;
        }
        
        // if they crossover
        return i > end1;
    }
    
};