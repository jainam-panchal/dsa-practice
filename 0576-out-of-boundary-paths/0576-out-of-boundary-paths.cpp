class Solution {
public:
    int M,N;
    const unsigned int MOD = 1000000007;
    int memo[51][51][51];
    
    int solve(int sr, int sc, int moves) {
        if(sr < 0 || sr >= M || sc < 0 || sc >= N) {
            return 1; // we found out of bound case
        }
        
        if(memo[sr][sc][moves] != -1)
            return memo[sr][sc][moves];
        
        // no moves left. retire
        if(moves <= 0) return 0;
        
        // move all possible way
        long long a = solve(sr+1, sc, moves-1) % MOD;
        long long b = solve(sr-1, sc, moves-1) % MOD;
        long long c = solve(sr, sc+1, moves-1) % MOD;
        long long d = solve(sr, sc-1, moves-1) % MOD;
        
        memo[sr][sc][moves] = ((a+b+c+d) % MOD);
        return memo[sr][sc][moves];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        memset(memo, -1, sizeof(memo));
        return solve(startRow, startColumn, maxMove);
    }
};