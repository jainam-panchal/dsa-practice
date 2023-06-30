class Solution {
public:
    int compress(vector<char>& chars) {

        //maintain count for individual character
        //store the ans temporarily in ans string
        int count=1;
        string ans;
        
        // start from index 1 till the end
        for(int i=1 ; i<=chars.size() ; i++) {
            
            //compare element to it's previous one
            // LOOP SHOULDN'T EXCEED THE VECTOR (error)
            if(i<chars.size() && chars[i] == chars[i-1]) {
                count++;
            }
            else {
                
                //if count==1 do not insert count
                if(count == 1) {
                    ans.push_back(chars[i-1]);
                }

                // else insert count
                else {
                    ans.push_back(chars[i-1]);
                    string c = to_string(count);
                    for(auto character : c) {
                        ans.push_back((char)character);
                    }
                    count = 1;
                }
            }
        }

        //adding ans to vector
        for(int i=0 ; i<ans.size() ; i++) {
            chars[i] = ans[i];
        }

        //returning valid size
        return ans.size();
    }
};