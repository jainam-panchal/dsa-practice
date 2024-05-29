class Solution {
private:
    void addone(string &s) {
        
        // Because when we add one to a binary
        // one will be only added to the first 0 from right to left
        
        int i = s.size() - 1;
        while(i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }
        if(i < 0) {
            s = '1' + s;
        } else {
            s[i] = '1';
        }
        
    }
    
public:
    int numSteps(string s) {
        
        int count = 0;
        
        while(s != "1") {
            
            int k = s.size()-1;
            // odd case
            if(s[k] == '1') {
                addone(s);
            } 
            // even case
            else {
                s.pop_back();
            }
            
            count++;
        }
        return count;
    }
};