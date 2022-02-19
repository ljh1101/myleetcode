/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-14 22:11:07
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-14 22:48:56
 */

/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

*/

//类似35题

/*
*简单的二分查找
*/

#include <vector>
using namespace std;



/*
执行用时：28 ms, 在所有 C++ 提交中击败了80.90%的用户
内存消耗：27 MB, 在所有 C++ 提交中击败了15.43%的用户
*/

//时间复杂度：O（log n）
//空间复杂度：O（1）


class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (target < nums[mid])
            {
                right = mid - 1;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
