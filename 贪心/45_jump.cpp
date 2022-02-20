/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-20 11:12:43
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-20 15:47:56
 */

/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

/*
*又是没想出来，思路大致可以，细节实现的时候比较混乱
*主要思想就是，从头开始，以第一跳的最大距离作为一个区间，遍历到区间尾部时，
*在这个区间里再找一个可以跳的最远的，作为下一个区间的尾部，依次类推
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(n)
    //空间复杂度：O(1)
    int jump(vector<int> &nums)
    {
        int len = nums.size();
        int jumpCount = 0, maxPos = 0, end = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (i <= maxPos)
            {
                maxPos = maxPos > (i + nums[i]) ? maxPos : (i + nums[i]);
                if(i==end)
                {
                    end=maxPos;
                    ++jumpCount;
                }
            }
        }
        return jumpCount;
    }
};