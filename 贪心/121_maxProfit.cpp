/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-18 11:00:12
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-18 11:33:56
 */

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

/*
*比较简单，但这好像是贪心思想，而不是动态规划
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(n)
    //空间复杂度：O(n)
    int maxProfit(vector<int> &prices)
    {
        int minNum = INT_MAX;
        int len = prices.size();
        vector<int> dp(len + 1, 0);
        for (int i = 0; i < len; i++)
        {
            minNum = prices[i] < minNum ? prices[i] : minNum;
            dp[i + 1] = max(dp[i], prices[i] - minNum);
        }
        return dp[len];
    }

    //时间复杂度：O(n)
    //空间复杂度：O(1)
    int maxProfit(vector<int> &prices)
    {
        int minNum = INT_MAX, maxProfit = 0;
        for (int price : prices)
        {
            minNum = min(price, minNum);
            maxProfit = max(maxProfit, price - minNum);
        }
        return maxProfit;
    }
};