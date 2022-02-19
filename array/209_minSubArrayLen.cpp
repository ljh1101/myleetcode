/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-16 21:42:57
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-16 22:20:26
 */

/*
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/

/*
*通过滑动窗口解决该问题
*遍历整个数组，累加每一个遍历的元素，如果当前累加值已经大于等于target，左侧边界向右移，再次判断
*记录最小长度
*/

#include <vector>
using namespace std;

//时间复杂度：O（n）
//空间复杂度：O（1）

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = nums.size();
        int minLen = INT16_MAX; //最小长度
        int sum = 0;            //子数组和
        for (int i = 0, j = 0; j < len; j++)//i为滑动窗口左侧指针，j为滑动窗口右侧指针
        {
            sum += nums[j];
            if (sum >= target)
            {
                while (sum - nums[i] >= target)
                {
                    sum -= nums[i++];
                }
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                }
            }
        }
        return minLen == INT16_MAX ? 0 : minLen;
    }
};