class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookie) {
        
        // TWO POINTER APPROACH : O(nlogn + mlogm),O(logn+logm)
        
        sort(children.begin() , children.end());
        sort(cookie.begin() , cookie.end());
        
        int currCookie = 0;
        int currChild = 0;
        
        while(currCookie < cookie.size() && currChild < children.size()) {
            if(cookie[currCookie] >= children[currChild]) {
                currChild++;
            }
            currCookie++;
        }
        
        return currChild;
    }
};