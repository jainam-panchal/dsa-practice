class Solution {
    public int minPatches(int[] nums, int n) {
        long maxreach = 0;
        int patches = 0;
        int i = 0;

        while (maxreach < n) {
            if (i < nums.length && nums[i] <= maxreach + 1) {
                // Use the current number to extend the reach
                maxreach += nums[i];
                i++;
            } else {
                // Add a patch to extend the reach
                patches++;
                maxreach += maxreach + 1;
            }
        }

        return patches;
    }

}