class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> val;
        
        for(auto i : nums) {
            val.push_back(to_string(i));
        }
        
        auto comp = [] (string a, string b) {
            return a+b > b+a;
        };
        
        sort(val.begin() , val.end() , comp);

        if(val[0] == "0") return "0";
        
        string ans;
        for(auto s : val) {
            ans += s;
        }
        
        
        return ans;
    }
};