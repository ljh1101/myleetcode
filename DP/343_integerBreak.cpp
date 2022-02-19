/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-07 15:48:28
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-10 11:29:31
 */

/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.
Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
*/

/*
 *看了题解，发现可以用dp法和数学方法
 *只考虑正整数n的结果可能比较难考虑，dp就是不是只考虑正整数n的结果，要考虑从2到n的结果，大正数的结果要用要小正数的结果
 *数学法是把任何数化成多个三的和再加上除三的余数，做乘法（数学结论）
 */

#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    //简单动态规划
    //时间复杂度：O（n2）
    //空间复杂度：O（n）
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);       // dp[i]表示将正整数i拆分成至少两个正整数的和之后，这些正整数的最大乘积。
        for (int i = 2; i <= n; i++) //计算dp[i]的值
        {
            int currMax = 0;
            for (int j = 1; j < i; j++)
            {
                currMax = max(currMax, max(j * (i - j), j * dp[i - j])); //状态转移公式
            }
            dp[i] = currMax;
        }
        return dp[n];
    }

    //数学法
    //时间复杂度：O（n）
    //空间复杂度：O（1）
    int integerBreak(int n)
    {
        if (n < 4)
            return n - 1;
        int result = 1;
        while (n > 4)
        {
            n = n - 3;
            result = result * 3;
        }
        return result * n;
    }
};