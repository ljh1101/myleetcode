/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-17 10:46:07
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-17 17:09:00
 */

/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn ）。

示例 1：
输入：x = 2.00000, n = 10
输出：1024.00000

示例 2：
输入：x = 2.10000, n = 3
输出：9.26100
*/

/*
*写的过程一波三折，用连乘的方法时间老超时，快速幂可大大缩减乘法次数
*快速幂就是把幂拆分为2的幂相加，把幂写成二进制的形式，每次除二求余判断是否为1
*若是一，就累加x的2的n次方。
*同时要注意特殊情况。
*/

#include <vector>
using namespace std;

//时间复杂度：O（logn）
//空间复杂度：O（1）
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1)
            return 1;
        else if (x == -1)
        {
            return n % 2 == 0 ? 1 : -1;
        }
        else
        {
            double result = 1.0;
            for (int i = n; i != 0; i /= 2)
            {
                if (i % 2 != 0)
                {
                    result *= x;
                }
                x *= x;
            }
            return n > 0 ? result : 1 / result;
        }
    }
};