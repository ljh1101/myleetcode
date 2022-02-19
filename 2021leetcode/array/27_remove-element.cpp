/*
 * @Author: Liu Jiahui 
 * @Date: 2021-01-16 16:08:59 
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2021-01-21 17:39:19
 */

/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 
示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。

2021.1.16
*/

/*
*惭愧，刚开始还是没写出来，没彻底明白双指针、满指针的作用。拖了好几天。
*!我觉得这里面最重要的是慢指针，慢指针之前的元素都是符合条件的元素，快指针负责找不符合条件的元素
*/
#include <vector>
using namespace std;

/*
*!执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：8.6 MB, 在所有 C++ 提交中击败了88.97%的用户
*/
//时间复杂度：O（n）
//空间复杂度：O（1）
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[j++] = nums[i];//*还是双指针，慢指针之前的都是符合条件的元素
            }
        }
        return j;
    }
};