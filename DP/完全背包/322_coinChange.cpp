/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-17 19:40:30
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-17 20:45:50
 */

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

/*
*很遗憾，又没有独立做出来，没想到dp可以初始化为较大的值，
*还是完全背包问题，如果假设每个硬币得质量为1，要求的是硬币能组成给定金额的最小质量
*状态转换方程就要改变为最小值问题，然后注意组不成的情况。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(Sn)，其中 S 是金额，n 是面额数。
    //空间复杂度：O(S)。
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT16_MAX);
        dp[0] = 0;
        for (auto coin : coins)
            for (int j = coin; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - coin] + 1);
        if (dp[amount] != INT16_MAX)
            return dp[amount];
        return -1;
    }
};