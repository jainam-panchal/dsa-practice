class Solution {
public:
    bool checkRecord(string s) {
        
        int flag = false;
        int absent = 0;
        int late = 0;
        
      
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == 'P') {
                flag = false;
                // cout << "first ";
            }
            else if(s[i] == 'A') {
                absent++;
                flag = false;
                // cout << "second ";
                if(absent >= 2) return false;
            }
            else if(s[i] == 'L') {
                if(!flag) {
                    flag = true;
                    late = 1;
                }
                else {
                    late++;
                    // cout << "third2 ";
                    if(late >= 3) {
                        return false;
                    }
                }
            }
        }
        
        return true;
   
    }
};