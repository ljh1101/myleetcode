/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-18 21:19:12
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-18 21:28:38
 */

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //贪心法
    //时间复杂度：O(n)
    //空间复杂度：O(1)
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
            maxProfit += prices[i + 1] > prices[i] ? prices[i + 1] - prices[i] : 0;
        return maxProfit;
    }
};