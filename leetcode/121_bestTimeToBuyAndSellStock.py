class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # lowest to highest
        # Brute force -> for each of, clculate the diff that the i is bigger
        n = len(prices)
        profit = 0

        l = 0
        r = 1
        ret_profit = 0
        while(r < n):
            # Profitable means a valid window
            if prices[l] < prices[r]:
                profit = prices[r] - prices[l]
                ret_profit = max(ret_profit, profit)
            else:
                # reset window
                l=r

            r += 1
            
        return ret_profit
