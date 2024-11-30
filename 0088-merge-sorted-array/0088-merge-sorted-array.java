class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int len = m + n;
        
        int [] temp = new int[len];
        
        int curr=0;
        int i=0 , j=0;
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                temp[curr] = nums1[i];
                i++;
            } else {
                temp[curr] = nums2[j];
                j++;
            }
            
            curr++;
        }
        
        while(i < m) {
            temp[curr] = nums1[i];
            i++;
            curr++;
        }
        
        while(j < n) {
            temp[curr] = nums2[j];
            j++;
            curr++;
        }
        
        for(i=0 ; i<len ; i++) {
            nums1[i] = temp[i];
        }
        
    }
}