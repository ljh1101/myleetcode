/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-25 11:49:33
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-25 11:50:09
 */

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
示例 1：
输入：m = 3, n = 7
输出：28
*/

/*
 *比较简单，主要是从问题中抽象出状态转移公式
 *最左侧列和最上侧行值为1，而每一个位置的值等于左侧位置的值加上侧位置的值
 *看了题解之后这题竟然还可以用组合数，属实是我孤陋寡闻了
 */
#include <vector>
using namespace std;
class Solution
{
public:
    //时间复杂度：O（mxn）
    //空间复杂度：O（mxn）
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) //第零行值恒唯一，不用考虑
        {
            for (int j = 1; j < n; j++) //第零行值恒唯一，不用考虑
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //状态转移公式
            }
        }
        return dp[m - 1][n - 1];
    }
};