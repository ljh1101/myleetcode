/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-24 10:38:09
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-10 11:20:43
 */

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
*/

class Solution
{
public:
    //爬楼梯
    //时间复杂度：O（n）
    //空间复杂度：O（n）
    int climbStairs(int n)
    {
        int *dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


    //爬楼梯
    //时间复杂度：O（n）
    //空间复杂度：O（1）
    int climbStairs(int n)
    {
        int dp1 = 0,dp2 = 0,dp3 = 1;
        for (int i = 1; i < n + 1; ++i)
        {
            dp1 = dp2; 
            dp2 = dp3; 
            dp3 = dp1 + dp2;
        }
        return dp3;
    }
};