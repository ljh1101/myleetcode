/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-16 10:43:18
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-16 11:09:22
 */

/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
*/


/*
*第二次写，还是不太熟悉。
*用双指针代替两个循环，快指针遇到数值等于val的元素就不做任何操作直接++，
*快指针遇到数值不等于val的元素就令慢指针所指的元素等于快指针所指的元素。
*这样就能把值等于val的元素忽略，其他元素从后向前覆盖
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
        int len = nums.size();
        int slow = 0;
        for (int fast = 0; fast < len; fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};