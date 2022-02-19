/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-24 10:09:25
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-24 10:56:02
 */

/*
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给你 n ，请计算 F(n) 。
示例 1：
输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
*/

/*
 *动态规划入门，斐波那契数。
 *设一个dp数组，大小为n+2（考虑n为零的情况，要先给 dp[0]和dp[1]赋值），然后后面每一项都是前面两数的和
 *看了解答之后发现也可以不设数组来降低空间复杂度。
 */

class Solution
{
public:
    //斐波那契数
    //时间复杂度：O（n）
    //空间复杂度：O（n）
    int fib(int n)
    {
        int *dp = new int[n + 2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};