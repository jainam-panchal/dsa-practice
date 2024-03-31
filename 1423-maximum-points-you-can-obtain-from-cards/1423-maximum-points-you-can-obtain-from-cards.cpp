class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int n = cardPoints.size();
        int windowSize = n - k;
        
        long long windowSum = 0;
        long long totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        // Calculate sum of first window
        for (int i = 0; i < windowSize; ++i) {
            windowSum += cardPoints[i];
        }
        
        int maxSum = totalSum - windowSum;
        
        // Slide the window and update maxSum
        for (int i = windowSize; i < n; ++i) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            maxSum = max(maxSum, static_cast<int>(totalSum - windowSum));
        }
        
        return maxSum;
    }
};