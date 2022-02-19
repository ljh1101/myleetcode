/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-16 19:16:21
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-16 20:48:47
 */

/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
*/


/*
*像是简单的选择排序
*找到数组的分界点，用两个指针分别向左向右的遍历，每次选择绝对值较小的元素
*放入新的数组，最后补上没遍历到的元素（未遍历到的元素仅可能在一侧）
*/
#include <vector>
#include <cmath>
using namespace std;

//时间复杂度：O（n）
//空间复杂度：O（1）

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> arr(len);
        int arrIndex = 0;            //作arr向量的下标
        int index = 0;               //最小正整数的下标
        for (; index < len; index++) //找最小正整数的下标
        {
            if (nums[index] >= 0)
                break;
        }
        int i = index-1, j = index;
        while (i >= 0 && j < len)//从小到大选择数放入arr
        {
            if (abs(nums[i]) > nums[j])
            {
                arr[arrIndex++] = pow(nums[j++], 2);
            }
            else
            {
                arr[arrIndex++] = pow(nums[i--], 2);
            }
        }

        while (arrIndex < len)//补上未放完的数
        {
            if (i >= 0)
            {
                arr[arrIndex++] = pow(nums[i--],2);
            }
            else
            {
                arr[arrIndex++] = pow(nums[j++],2);
            }
        }
        return arr;
    }
};
