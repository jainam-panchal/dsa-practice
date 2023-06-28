class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i=0;
        int n=s.size();

        while(i<n){
            
            // skipping spaces
            while(i<n && s[i] == ' ')
                i++;
            if(i>=n) break;

            // i on the first letter and j on the last
            int j=i+1;
            while(j<n && s[j] != ' ')
                j++;
            
            // adding sub string to ans
            string sub = s.substr(i,j-i);
            
            // for first letter
            if(result.size() == 0)
                result = sub;
            else
                result = sub + ' ' + result;
            
            // check for another words
            i = j + 1;
        }

        return result;
    }
};