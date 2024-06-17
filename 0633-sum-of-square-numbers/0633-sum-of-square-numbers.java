class Solution {
    public boolean judgeSquareSum(int c) {
        int left = 0;
        int right = (int)Math.sqrt(c);

        while (left <= right) {
            long leftSquare = (long)left * left;
            long rightSquare = (long)right * right;
            long total = leftSquare + rightSquare;

            if (total == c) {
                return true;
            } else if (total > c) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
}
