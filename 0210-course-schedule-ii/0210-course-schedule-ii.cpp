class Solution {
private:
    void topoSort(unordered_map<int, vector<int>> &mp , vector<int> &indegree , int &crs, vector<int> &ans) {
        int count = 0;
        queue<int> que;
        for(int i=0 ; i<indegree.size() ; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            ans.push_back(u);
            
            for(int i=0 ; i<mp[u].size() ; i++) {
                int x = mp[u][i];
                indegree[x]--;
                
                if(indegree[x] == 0) {
                    que.push(x);
                    count++;
                }
            }
        }
}
public:
    vector<int> findOrder(int crs, vector<vector<int>>& prerequisites) {
        // khan's algo - toposort
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(crs, 0);
        
        for(auto pre : prerequisites) {
            int final = pre[0];
            int req = pre[1];
            
            mp[req].push_back(final);
            indegree[final]++;
        }
        
        vector<int> ans;
        topoSort(mp, indegree, crs, ans); 
        if(ans.size() != crs)
            return {};
        return ans;
    }
};