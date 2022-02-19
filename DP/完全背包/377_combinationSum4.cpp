/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-16 18:52:37
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-17 20:46:17
 */

/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.
Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/

/*
*跟518题很像，518题是组合，本题是排列，跟上一题相比交换一下循环次序即可。
*刚开始确实没懂，这两题多对比一下。

*求装满背包有几种方法，递归公式都是一样的，没有什么差别，但关键在于遍历顺序！
*本题与动态规划：518.零钱兑换II就是一个鲜明的对比，一个是求排列，一个是求组合，遍历顺序完全不同。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= target; j++)
            for (auto num : nums)
                if (j >= num && dp[j - num] < INT_MAX - dp[j])
                    dp[j] += dp[j - num];

        return dp[target];
    }
};