class Solution {
    public int helper(int[] prices, int i, boolean doWeHaveAnything, int[][] dp) {
        if (i >= prices.length) {
            return 0;
        }

        int hold = doWeHaveAnything ? 1 : 0;

        if (dp[i][hold] != -1) {
            return dp[i][hold];
        }

        if (doWeHaveAnything) {
            // If holding, we can sell or skip
            int ifSold = prices[i] + helper(prices, i + 1, false, dp); // Sell
            int ifSkipped = helper(prices, i + 1, true, dp); // Skip
            dp[i][hold] = Math.max(ifSold, ifSkipped);
        } else {
            // If not holding, we can buy or skip
            int ifBought = -prices[i] + helper(prices, i + 1, true, dp); // Buy
            int ifSkipped = helper(prices, i + 1, false, dp); // Skip
            dp[i][hold] = Math.max(ifBought, ifSkipped);
        }

        return dp[i][hold];
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2]; // State: (i, holding stock or not)
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return helper(prices, 0, false, dp);
    }
}
