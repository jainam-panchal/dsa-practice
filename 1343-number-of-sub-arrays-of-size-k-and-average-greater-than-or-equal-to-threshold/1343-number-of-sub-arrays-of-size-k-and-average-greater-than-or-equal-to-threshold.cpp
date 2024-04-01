class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int count = 0;
        double sum = 0;

        int i = 0, j = 0;

        while(j < arr.size()) {
            
            sum += arr[j];

            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                double avg = sum / (double)k;
                // cout << "avg : " << avg << endl;

                if( avg >= threshold) {
                    count++;
                }
                sum -= arr[i];
                i++;
                j++;
            }
        }
        
        return count;
    }
};