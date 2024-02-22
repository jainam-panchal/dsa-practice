class Solution {
private:
    int nCr(int n, int r) {
        long long ans = 1;
        
        for(int i=0 ; i<r ; i++) {
            ans = ans * (n-i);
            ans = ans / (i+1);
        }
        
        return (int) ans;
    }
    
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        rowIndex += 1;
        
        for(int i=1 ; i<=rowIndex ; i++) {
            ans.push_back(nCr(rowIndex-1,i-1));
        }
        
        return ans;
    }
};