/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-10 11:19:17
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-10 13:04:31
 */

/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Example 1:
Input: n = 3
Output: 5
*/

/*
*数学法是一个递推公式
*dp刚开始思路有点偏，没能把问题正确的抽象出来，我刚开始想的是计算树的个数，这样没法用dp
*要抽象成不同数字作顶点，分别计算左右子树的个数，然后累加的问题
*/
#include <vector>
using namespace std;
class Solution
{
public:
    //数学法
    //时间复杂度：O（n）
    //空间复杂度：O（1）
    int numTrees(int n)
    {
        long long res = 1;
        for (int i = 0; i < n; i++)
        {
            res = res * 2 * (2 * i + 1) / (i + 2);//数学法递推
        }
        return int(res);
    }

    // DP
    //时间复杂度：O（n2）
    //空间复杂度：O（n）
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }  
        }
        return dp[n];
    }
};