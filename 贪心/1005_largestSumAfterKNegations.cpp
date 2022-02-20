/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-20 15:40:00
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-20 17:35:42
 */

/*
Given an integer array nums and an integer k, modify the array in the following way:
choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.
Return the largest possible sum of the array after modifying it in this way.

Example 1:
Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
*/

/*
*做贪心的题好费劲，老是有情况想不到
*这道题的思路：如果有负数，在k>0的情况下先把负数取相反数并k--，此时如果k % 2 == 1，那么要找一个最小数再取相反数
*要考虑都是正数，都是负数，正数负数都有三种情况。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int len = nums.size();
        int sum = 0, minNumIndex = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++)
        {
            if (k > 0 && nums[i] < 0)
            {
                nums[i] = -nums[i];
                --k;
                minNumIndex = i;
            }
        }
        if (k % 2 == 1)
        {
            if (minNumIndex + 1 == len || minNumIndex == 0)
            {
                nums[minNumIndex] = -nums[minNumIndex];
            }
            else
            {
                int temp = nums[minNumIndex + 1] > nums[minNumIndex] ? minNumIndex : minNumIndex + 1;
                nums[temp] = -nums[temp];
            }
        }
        for (int i = 0; i < len; i++)
            sum += nums[i];

        return sum;
    }
};