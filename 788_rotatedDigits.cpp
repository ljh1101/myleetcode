/*
 * @Author: Liu Jiahui 
 * @Date: 2022-03-11 19:42:16 
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-17 21:35:28
 */

/*
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

示例：
输入: 10
输出: 4
解释: 
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
*/

/*

*/

class Solution
{
public:
    int rotatedDigits(int n)
    {
        int result = 0;
        for (int i = 2; i <= n; i++)
        {
            int nums = i;
            bool flag = false;
            while (nums != 0)
            {
                int num = nums % 10;
                if (num == 3 || num == 4 || num == 7)
                {
                    break;
                }
                if (num == 2 || num == 5 || num == 6 || num == 9)
                {
                    flag = true;
                }
                nums /= 10;
            }
            if (flag == true && nums == 0)
            {
                ++result;
            }
        }
        return result;
    }
};

