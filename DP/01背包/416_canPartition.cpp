/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-14 15:34:52
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-Mo 06:08:29
 */

/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

/*
*01背包问题的变形，把背包能装的最大价值换成了背包能不能装固定的重量，这个重量的物品总重量的一半
*这里dp数组既可以用bool型也可用int型，int型好理解，最后判断一下即可
*我对背包问题的理解还不够，还得继续努力。
*/
/*
*01背包问题核心代码
for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
*/

#include <vector>
using namespace std;

class Solution
{
public:
    //时间复杂度：O（n*target）
    //空间复杂度：O（target）
    bool canPartition(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0, target;
        for (int i = 0; i < len; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < len; i++)
            for (int j = target; j >= nums[i]; j--)
                dp[j] = dp[j] | dp[j - nums[i]];

        return dp[target];
    }
};