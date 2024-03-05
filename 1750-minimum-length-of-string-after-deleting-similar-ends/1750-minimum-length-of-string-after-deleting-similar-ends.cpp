class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        if (n == 0)
            return 0;

        int left = 0, right = n - 1;

        while (left < right && s[left] == s[right]) {
            char current = s[left];

            while (left <= right && s[left] == current) {
                left++;
            }

            while (left <= right && s[right] == current) {
                right--;
            }
        }

        return max(0, right - left + 1);
    }
};