/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-19 11:24:05
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-20 11:11:55
 */

/*
A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
Given an integer array nums, return the length of the longest wiggle subsequence of nums.

Example 1:
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
*/

/*
*麻了，自己想的方法没考虑前面几个一直相等的情况，倒来倒去做不出来，方法不严谨
*主要思想就是：如果相邻两数之差大于零跟小于零交替出现，计数就累加，但是要考虑相邻两数相等的情况
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //贪心法
    //时间复杂度：O(n)
    //空间复杂度：O(1)
    int wiggleMaxLength(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return 1;
        int maxNum = nums[1] == nums[0] ? 1 : 2;
        int flag = nums[1] - nums[0];
        for (int i = 1; i < len - 1; i++)
        {
            int diff = nums[i + 1] - nums[i];
            if ((flag >= 0 && diff < 0) || (flag <= 0 && diff > 0))
            {
                ++maxNum;
                flag = diff;
            }
        }
        return maxNum;
    }
};