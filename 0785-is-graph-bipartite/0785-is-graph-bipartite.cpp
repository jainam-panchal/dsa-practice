class Solution {
public:
    
    bool checkDFSBipartite(vector<vector<int>>& mp, vector<int> &color, int u, int currColor) {
        
        // first color the node
        color[u] = currColor;
        
        // paint all adj
        for(int i=0 ; i<mp[u].size() ; i++) {
            int val = mp[u][i];
            int newColor = currColor == 1? 0 : 1;
            
            // already paint in same color
            if(color[val] == currColor) return false;
            
            // not visited
            if(color[val] == -1) {
                // check for that node, is the painting possible?
                if(checkDFSBipartite(mp, color, val, newColor) == false)
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& mp) {
        vector<int> color(mp.size(), -1);
        
        for(int i=0 ; i<mp.size() ; i++) {
            if(color[i] == -1 && !checkDFSBipartite(mp, color, i, 1)) {
                return false;
            }
        }
        
        return true;
    }
};