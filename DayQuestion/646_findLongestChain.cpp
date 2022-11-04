/*
 * @Author: Liu Jiahui
 * @Date: 2022-09-03 16:43:40
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-09-03 17:25:10
 */

/*
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a,
b) 后面。我们用这种形式来构造一个数对链。
给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
*/

/*
* 贪心思想，一开始没做出来，比较的是前一个数据元素，
* 其实跟前一个元素没关系，主要是后一个元素，后一个元素小了，才能给前一个元素腾出更多空间。
*/

#include <algorithm>
#include <cstdint>
#include <vector>
using namespace std;

class Solution {
  public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        unsigned int count = 0;
        int comp = INT16_MIN;
        sort(pairs.begin(), pairs.end(),
             [](vector<int> a, vector<int> b) -> bool { return b[1] > a[1]; });
        for (auto &ve : pairs) {
            if (ve[0] > comp) {
                ++count;
                comp = ve[1];
            }
        }
        return count;
    }
};