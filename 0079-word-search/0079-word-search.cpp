class Solution {
private:
    bool func(vector<vector<char>> &board, string word, int i, int j, int index) {
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size()) {
            return false;
        }
        
        // checking if the string char matches or already used
        if(board[i][j] != word[index] || board[i][j] == '*') {
            return false;
        }
        
        // if we're already at the last
        if(index == word.size() - 1) return true;
        
        // to check if the element is already used or not
        char backup = board[i][j];
        board[i][j] = '*';
        
        bool flag = func(board, word, i+1, j, index+1) ||
                    func(board, word, i-1, j, index+1) ||
                    func(board, word, i, j+1, index+1) ||
                    func(board, word, i, j-1, index+1);
        
        board[i][j] = backup;
        
        return flag;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0 ; i<board.size() ; i++) {
            for(int j=0 ; j<board[0].size() ; j++) {
                if(func(board , word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};