/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-17 16:11:06
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-17 18:02:35
 */

/*
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
*/

/*
*初看毫无头绪，还是看了别人的思路才写的
*循环n2次，按照题目中所要求的顺序进行遍历，需要设置四个边界，每遍历完一行或一列后对用边界收缩
*按照遍历的顺序依次赋值即可
*/

#include <vector>
using namespace std;

//时间复杂度：O（n2）
//空间复杂度：O（1）

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int left = 0, right = n - 1, up = 0, down = n - 1; //定义边界
        int x = 0, y = -1;                                 //遍历所用下标
        int n2 = n * n;
        for (int i = 0; i < n2;)
        {
            while (y < right) //向右走
            {
                result[x][++y] = ++i;
            }
            ++up;            //上边界加一
            while (x < down) //向下走
            {
                result[++x][y] = ++i;
            }
            --right;         //右边界减一
            while (y > left) //向左走
            {
                result[x][--y] = ++i;
            }
            --down;        //下边界减一
            while (x > up) //向上走
            {
                result[--x][y] = ++i;
            }
            ++left;//左边界加一
        }

        return result;
    }
};