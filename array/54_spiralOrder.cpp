/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-17 17:18:46
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-17 18:07:23
 */

/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
*/

/*
*类似于59题，根据已知条件遍历向量，依次赋值给新的数组，同样要注意边界问题。
*有一点要注意的是，这个问题要加入判断退出，因为这不是方阵，遍历完成后有可能会出现回退的情况，要及时判断并退出。
*/

#include <vector>
using namespace std;

//时间复杂度：O（m*n）
//空间复杂度：O（1）

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int xLen = matrix.size();
        int yLen = matrix[0].size();
        int len = xLen * yLen;
        vector<int> result(len);
        int left = 0, right = yLen - 1, up = 0, down = xLen - 1; //定义边界
        int x = 0, y = -1;                                       //遍历所用下标

        for (int i = 0; i < len;)
        {
            while (y < right) //向右走
            {
                result[i++] = matrix[x][++y];
            }
            if (i == len)//根据判断决定是否退出
                break;
            ++up;            //上边界加一
            while (x < down) //向下走
            {
                result[i++] = matrix[++x][y];
            }
             if (i == len)
                break;
            --right;         //右边界减一
            while (y > left) //向左走
            {
                result[i++] = matrix[x][--y];
            }
             if (i == len)
                break;
            --down;        //下边界减一
            while (x > up) //向上走
            {
                result[i++] = matrix[--x][y];
            }
            ++left;//左边界加一
        }
        return result;
    }
};