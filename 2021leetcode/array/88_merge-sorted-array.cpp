/*
 * @Author: Liu Jiahui 
 * @Date: 2021-01-27 20:13:49 
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2021-01-27 21:03:21
 */

/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
*/

/*
*双指针从后往前排，可惜我没想出来。
*这种方法比从前往后排降低了空间复杂度
*/

#include <vector>
using namespace std;
//*力扣的执行时间真是玄学
/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了96.42%的用户
*/
//*时间复杂度：O（m+n）
//*空间复杂度：O（1）

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int index = m + n - 1; //*赋值位置的下标
        for (int i = m - 1, j = n - 1; i >= 0, j >= 0;)
        {
            if (i == -1 || nums1[i] < nums2[j]) //*比较大小，从后往前赋值。还有num1遍历完，num2还没遍历完的情况
            {
                nums1[index--] = nums2[j--];
            }
            else
            {
                nums1[index--] = nums1[i--];
            }
        }
    }
};