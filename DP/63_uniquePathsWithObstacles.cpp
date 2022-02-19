/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-07 13:45:43
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-07 15:48:53
 */

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

/*
 *相对62题，添加了障碍，只要把障碍位置的值设为0即可
 *同时要考虑第零行和第零列的情况
 */

#include <vector>
using namespace std;

class Solution
{
public:
    //时间复杂度：O（mxn）
    //空间复杂度：O（mxn）
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)//遇到障碍物设为0
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i == 0 && j != 0)
                        dp[i][j] = dp[i][j - 1];
                    else if (j == 0 && i != 0)
                        dp[i][j] = dp[i - 1][j];
                    else if (i != 0 && j != 0)
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //状态转移公式
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};