## 121. Best Time to Buy and Sell Stock
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

***Solution:***

memo[i][0]: On the ith day, the max value we have if we dont hold a stock. Either we maintain the previous condition or we sell the stock --> max(memo[i - 1][0], memo[i - 1][1] + prices[i])

memo[i][1]: On the ith day, the max value we have if we do hold a stock. Either we main the previous condition or we buy the stock --> max(memo[i - 1][1], -prices[i])



```
int maxProfit(vector<int>& prices) {
    vector<vector<int>> memo(prices.size(), vector<int>(2 , 0));
    memo[0][0] = 0;
    memo[0][1] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
        memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);
        memo[i][1] = max(memo[i - 1][1], -prices[i]);
    }
    return memo[prices.size() - 1][0];
}
```

For 122. buy and sell stock II(https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/), the only difference is for memo[i][1], the max value we can get is we either maintain the previous condition or we decide to buy a stock, we might have already earned some money before:
```
memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);

memo[i][1] = max(memo[i - 1][1], memo[i - 1][0] - prices[i]);
```