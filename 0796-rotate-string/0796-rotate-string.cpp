class Solution {
public:
    bool rotateString(string str1, string str2) {
        if(str1.size() != str2.size())
            return false;
        
        int size = str1.size();
        while(size) {
            // check if it's equal
            if(str1 == str2) return true;
            
            // rotate it
            int temp = str2[0];
            for(int i=1 ; i<str2.size() ; i++) {
                str2[i-1] = str2[i];
            }
            str2[str2.size()-1] = temp;
            
            size--;
        }
        
        return false;
    }
};