/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-16 11:04:51
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-21 11:46:43
 */

/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

输入：nums = [1,1,2]
输出：2, nums = [1,2]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
*/


/*
*对双指针的运用更深刻了一点。主要就是如果当前快指针所指向的元素要被删除，
*那就不管他，直接跳过，用后面的元素覆盖他即可。
*/
#include <vector>
using namespace std;

/*
执行用时：8 ms, 在所有 C++ 提交中击败了84.26%的用户
内存消耗：17.8 MB, 在所有 C++ 提交中击败了82.50%的用户
*/
//时间复杂度：O（n）
//空间复杂度：O（1）

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1) //考虑特殊情况
            return len;
        int slow = 0;
        for (int fast = 1; fast < len; fast++)
        {
            if (nums[slow] != nums[fast])
            {
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
