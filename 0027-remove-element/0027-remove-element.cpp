class Solution {
public:
    int removeElement(vector<int>& A, int VAL) {
        int m = 0;
        for(int i = 0; i < A.size(); i++){
           if(A[i] != VAL){
               A[m] = A[i];
               m++;
           }
       }
       return m;
    }
};