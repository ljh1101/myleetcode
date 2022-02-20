/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-20 09:48:57
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-20 15:48:16
 */

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

/*
 *没有有效的抽象出来,我只是想着每次要走几步，才能到达最后。没想到可以维护一个变量作为能达到的最远距离，在遍历中维护实时维护他即可
 *要转换一下思维
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(n)
    //空间复杂度：O(1)
    bool canJump(vector<int> &nums)
    {
        int cur = nums[0];
        int i = 1;
        for (; cur != 0 && i < nums.size(); i++)
        {
            --cur;
            if (cur < nums[i])
                cur = nums[i];
        }
        return i == nums.size();
    }
};