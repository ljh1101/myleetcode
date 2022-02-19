/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-15 10:19:35
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-15 12:48:43
 */

/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/

/*
////每个数的重量看作1或-1.背包容量在-len到len之间。
*还是想错了，这还是个找子集的问题，这个问题可转化为找一个正子集一个负子集，使两个子集之和等于target
*然后就变成了在背包容量为target1时，背包所能装物品质量和为target1的个数
*把问题抽象转化出来太难了
*要搞清楚dp数组的含义
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        //时间复杂度：O（n*target1）
        //空间复杂度：O（target1）
        int len = nums.size();
        int sum = 0, target1; //要找的目标质量和
        for (int i = 0; i < len; i++)
            sum += nums[i];
        target1 = sum - target;
        if (target1 < 0 || target1 % 2 == 1)
            return 0;
        target1 /= 2; //目标质量和的值
        vector<int> dp(target1 + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < len; i++)
            for (int j = target1; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        return dp[target1];
    }
};