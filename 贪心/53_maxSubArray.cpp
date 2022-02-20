/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-20 09:10:25
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-20 09:37:54
 */

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

/*
 *二刷，还是有一点模糊，主要思想就是，如果前一段子序列的和为负数，那么舍弃这一段子序列，同时要有一个变量保存最大子序列和
 */

#include <vector>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(n)
    //空间复杂度：O(1)
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum < nums[i])
                sum = nums[i];
            maxSum = maxSum > sum ? maxSum : sum;
        }
        return maxSum;
    }
};