/*
 * @Author: Liu Jiahui
 * @Date: 2021-01-23 11:48:03
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-14 23:06:44
 */

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

2021.1.23
*/

/*
 *主要思想就是二分查找，比线性查找平均时间时间复杂度更低。
 *刚开始知道是用二分查找，但是写出来的不对，总是有情况对不上，找不好确定位置。
 *刚开始二分查找的尾部选用的是最后元素下一个空位置的下标，后来用了最后元素的下标
 *中间元素的确定的方法也不同
 */

#include <vector>
using namespace std;

//这个方法没通过
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        int divs = right / 2;

        if (target < nums[left])
        {
            return left;
        }
        else if (target > nums[right - 1])
        {
            return right;
        }

        while (left <= right)
        {
            if (target < nums[divs])
            {
                right = divs - 1;
                divs = (divs + left) / 2;
            }
            else if (target > nums[divs])
            {
                left = divs + 1;
                divs = (divs + right) / 2;
            }
            else
            {
                return divs;
            }
        }
        return divs + 1;
    }
};

/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：9.4 MB, 在所有 C++ 提交中击败了96.17%的用户
*/

//时间复杂度：O（log n）
//空间复杂度：O（1）

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int aws = right + 1;
        if (target < nums[left])
        {
            return left;
        }
        else if (target > nums[right])
        {
            return right + 1;
        }

        while (left <= right)
        {
            int divs = ((right - left) >> 1) + left;
            if (target <= nums[divs]) // target若小于nums[divs]，则有可能可以插入到这里，若等于，则搜索成功
            {
                aws = divs;
                right = divs - 1;
            }
            else if (target > nums[divs])
            {
                left = divs + 1;
            }
        }
        return aws;
    }
};
