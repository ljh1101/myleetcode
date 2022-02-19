/*
 * @Author: Liu Jiahui 
 * @Date: 2021-01-24 21:23:49 
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2021-01-25 23:07:17
 */

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

/*
*这次是做的最快的一次！
*动态规划，这题之前做过一次，但是想不起来了。
*每向后遍历一个，保存前面最大子数组的和。
*比较两次，第一次，前面某元素到当前元素的和跟当前遍历的元素比较，较大者作为当前的结果
*第二次，当前结果跟前面最大子数组和比较，较大者作为最终结果。
*/

#include <vector>
using namespace std;

/*
执行用时：648 ms, 在所有 C++ 提交中击败了5.06%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了94.47%的用户
*/
//*时间复杂度：O（n2）
//*空间复杂度：O（1）
//*暴力法
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int len = nums.size();
        int max = INT_MIN;

        for (int i = 0; i < len; i++)
        {
            int temp = 0;
            for (int j = i; j < len; j++)
            {
                temp += nums[j];
                if (max < temp)
                {
                    max = temp;
                }
            }
        }
        return max;
    }
};


/*
执行用时：4 ms, 在所有 C++ 提交中击败了99.59%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了95.72%的用户
*/
//*时间复杂度：O（n）
//*空间复杂度：O（1）
//*动态规划
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = INT_MIN;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp += nums[i];
            if (nums[i] > temp)
            {
                temp = nums[i];
            }
            max = max > temp ? max : temp;//*保留已经遍历过的最大子数组和，不用再循环一次
        }
        return max;
    }
};