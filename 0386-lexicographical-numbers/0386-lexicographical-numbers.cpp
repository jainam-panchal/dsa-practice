class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int start = 1 ; start <= 9 ; start++) {
            helper(start, n, ans);
        }
        
        return ans;
    }

private:
    void helper(int val , int n , vector<int> &ans) {
        if(val > n) return;
        ans.push_back(val);
        
        for(int i=0; i<=9 ; i++) {
            int next = val * 10 + i;
            if(next <= n) {
                helper(next , n , ans);
            }
            else break;
        }
    }
    
};