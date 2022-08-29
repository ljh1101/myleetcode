/*
 * @Author: Liu Jiahui
 * @Date: 2022-08-29 17:13:13
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-29 17:31:29
 */

/*
给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn]
的格式排列。 请你将数组按 [x1,y1,x2,y2,...,xn,yn]
格式重新排列，返回重排后的数组。
*/

#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> res(2 * n);
        int m = 0;
        for (int i = 0; i < n; i++) {
            res[m++] = move(nums[i]);
            res[m++] = move(nums[i + n]);

            // res.emplace_back(move(nums[i]));
            // res.emplace_back(move(nums[i + n]));
        }
        return res;
    }
};