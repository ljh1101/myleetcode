/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-16 16:27:56
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-16 18:53:49
 */

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

/*
*完全背包
*很好抽象，套代码就能ac
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins)
            for (int j = coin; j <= amount; j++)
                dp[j] += dp[j - coin];

        return dp[amount];
    }
};