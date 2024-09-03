class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // checking each row        
        for(int i=0 ; i<9 ; i++) {
            unordered_map<int, int> mp;
            for(int j=0 ; j<9 ; j++) {
                if(board[i][j] != '.' && mp.find(board[i][j]) != mp.end()) {
                    return false;
                }
                mp[board[i][j]]++;
            }
        }
        
        // checking each col
        for(int j=0 ; j<9 ; j++) {
            unordered_map<int, int> mp;
            for(int i=0 ; i<9 ; i++) {
                if(board[i][j] != '.' && mp.find(board[i][j]) != mp.end()) {
                    return false;
                }
                mp[board[i][j]]++;
            }
            
        }
        
        // 3x3 box validation
        for(int i=0 ; i<9 ; i+=3) {
            for(int j=0 ; j<9 ; j+=3) {
                
                unordered_map<int, int> mp;
                
                for(int l=i ; l<i+3 ; l++) {
                    for(int m=j ; m<j+3 ; m++) {
                        if(board[l][m] != '.' && mp.find(board[l][m]) != mp.end()) {
                            return false;
                        }
                        mp[board[l][m]]++;
                    }
                }
                
            }
        }
        
        return true;
        
    }
};