class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<vector<double>> pq;
        
        for(int i=0 ; i<arr.size() ; i++) {
            for(int j=i+1 ; j<arr.size() ; j++) {
                
                double div = double(arr[i]) / double(arr[j]);
                pq.push({div, double(arr[i]) , double(arr[j])});
                
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        
        auto topEle = pq.top();
        return {int(topEle[1]) , int(topEle[2])};
    }
};