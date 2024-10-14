class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q(nums.begin(),nums.end());
        long long sum =0;
        for(int i=0;i<k;i++){
            sum += q.top();
            long long ele = q.top()%3==0 ? q.top()/3:q.top()/3+1;
            q.pop();
            q.push(ele);
        }
        return sum;
    }
};