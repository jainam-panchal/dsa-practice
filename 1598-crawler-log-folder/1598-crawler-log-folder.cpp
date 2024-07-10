class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> dir;
        
        for (auto log : logs) {
            if (log == "../") {
                if (!dir.empty()) {
                    dir.pop();
                }
            } else if (log != "./") {
                dir.push(1);
            }
        }
        
        return dir.size();
    }
};