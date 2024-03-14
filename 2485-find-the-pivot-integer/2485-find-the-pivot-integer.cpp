class Solution {
public:
    int pivotInteger(int n) {
        int totalSum=n*(n+1)/2,preSum=0;
        for(int i=1;i<=n;i++){
            if(totalSum-preSum==i){
                return i;
            }
            preSum+=i;
            totalSum-=i;
        }
        return -1;
    }
};