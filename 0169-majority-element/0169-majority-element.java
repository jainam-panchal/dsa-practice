class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer , Integer> hashMap = new HashMap<>();
        
        for(int i=0 ; i<nums.length ; i++) {
            hashMap.put(nums[i] , hashMap.getOrDefault(nums[i] , 0) + 1);
        }
        
        int threshold = (nums.length / 2) + 1;
        
        for(HashMap.Entry<Integer , Integer> entry : hashMap.entrySet()) {
            if(entry.getValue() >= threshold) {
                return entry.getKey();
            }
        }
        
        return -1;
    }
}