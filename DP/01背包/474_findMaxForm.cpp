/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-15 16:25:51
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-15 16:26:37
 */

/*
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
*/

/*
*又是看了别人的思路才做出来的，想到了要三层循环，但状态转移方程没搞定
*这是一个三维动态规划问题，因为背包由两种容量，按照题意，要求的时背包能放的物品个数，所以物品价值都为1.
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(lmn + L)，其中l是数组 strs的长度，L是数组strs中的所有字符串的长度之和。
    //空间复杂度：O(mn)
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto str : strs)
        {
            int zeros = 0, ones = 0;
            for (auto ch : str)
            {
                if (ch == '0')
                    ++zeros;
                else
                    ++ones;
            }
            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
        return dp[m][n];
    }
};