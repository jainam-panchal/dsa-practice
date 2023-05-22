class Solution {
public:
    int getPivot(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        int mid = start + (end-start)/2 ;

        while(start < end)
        {
            if(arr[mid] >= arr[0]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return start;
    }
    int binarySearch(vector<int>& arr,int start,int end, int key) {
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            if(arr[mid] == key)
                return mid;
            else if(arr[mid]>key)
                end = mid - 1;
            else
                start = mid + 1;

            mid = start + (end-start)/2;
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int pivot = getPivot(arr);
        int n = arr.size();
        if(arr[pivot]<=target && target<=arr[n-1]) {
            return binarySearch(arr,pivot,n-1,target);
        }
        else
            return binarySearch(arr,0,pivot-1,target);

        return -1;
    }
};