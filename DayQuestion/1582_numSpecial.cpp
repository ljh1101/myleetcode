/*
 * @Author: Liu Jiahui
 * @Date: 2022-09-04 12:29:48
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-09-04 12:55:38
 */

/*
给你一个大小为 rows x cols 的矩阵 mat，其中 mat[i][j] 是 0 或 1，请返回 矩阵 mat
中特殊位置的数目 。 特殊位置 定义：如果 mat[i][j] == 1 并且第 i 行和第 j
列中的所有其他元素均为 0（行和列的下标均 从 0 开始 ）， 则位置 (i, j)
被称为特殊位置。
*/
#include <vector>
using namespace std;

class Solution {
  public:
    int numSpecial(vector<vector<int>>& mat)
    {
        unsigned int r = mat.size();
        unsigned int c = mat[0].size();
        vector<int> rowSum(r, 0);
        vector<int> colSum(c, 0);
        int res = 0;
        for (size_t i = 0; i < r; ++i)
            for (size_t j = 0; j < c; ++j)
                if (mat[i][j] == 1) {
                    ++rowSum[i];
                    ++colSum[j];
                }
        for (size_t i = 0; i < r; ++i)
            for (size_t j = 0; j < c; ++j)
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1)
                    ++res;
        return res;
    }
};