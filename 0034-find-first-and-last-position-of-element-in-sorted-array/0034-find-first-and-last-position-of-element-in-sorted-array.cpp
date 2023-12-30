class Solution
{
public:
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int firstOcc = -1;
        int lastOcc = -1;
        
        int start = 0, end = arr.size()-1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == target) {
                firstOcc = mid;
                end = mid - 1;
            }
            else if(arr[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        start = 0; end = arr.size()-1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(arr[mid] == target) {
                lastOcc = mid;
                start = mid + 1;
            }
            else if(arr[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return {firstOcc, lastOcc};
    }      
};