class Solution {
bool isPalindrome(string str, int i, int j) {
    if(i > j) 
        return true;
    if(str[i] == str[j]) 
        return isPalindrome(str,i+1, j-1);
    return false;
}
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0 ; i<words.size() ; i++) {
            if(isPalindrome(words[i], 0, words[i].size()-1))
                return words[i];
        }
        return "";
    }
};