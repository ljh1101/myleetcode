/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-18 09:47:37
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-18 10:09:31
 */

/*
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
*/

/*
*跟322题差不多，比较简单，就是我还多用了一些空间存完全平方数
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
//时间复杂度：O(n\sqrt{n})
//空间复杂度：O(n)
    int numSquares(int n)
    {
        vector<int> nums;
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
            nums.push_back(i * i);
        for (int num : nums)
            for (int j = num; j <= n; j++)
                dp[j] = min(dp[j], dp[j - num] + 1);
        return dp[n];
    }
};