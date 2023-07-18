## 309. Best Time to Buy and Sell Stock with Cooldown
(https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

***Solution:***


```
int maxProfit(vector<int>& prices) {
    // we have 3 conditions
    // memo[i][0]: the max val when we have a stock (either from previously or we just buy one)
    // memo[i][1]: the max val when we don't have a stock bc just sold
    // memo[i][2]: the max val when we don't have a stock bc previous sold

    vector<vector<int>> memo(prices.size(), vector<int>(3, 0));
    memo[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        memo[i][0] = max(memo[i - 1][0], memo[i - 1][2] - prices[i]);
        memo[i][1] = memo[i - 1][0] + prices[i]; // have to sell it today
        memo[i][2] = max(memo[i - 1][2], memo[i - 1][1]);
    }
    return max(memo[prices.size() - 1][1], memo[prices.size() - 1][2]);
}
```

## 714. Best Time to Buy and Sell Stock with Transaction Fee
(https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)
```
int maxProfit(vector<int>& prices, int fee) {
    vector<int> memo(2, 0);
    memo[0] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        memo[0] = max(memo[0], memo[1] - prices[i]);
        memo[1] = max(memo[1], memo[0] + prices[i] - fee);
    }
    return memo[1];
}
```