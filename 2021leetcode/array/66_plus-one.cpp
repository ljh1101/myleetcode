/*
 * @Author: Liu Jiahui
 * @Date: 2021-01-25 22:23:55
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2021-01-25 23:07:39
 */

/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
*/

/*
 *这道题思虑比较简单，处理好特殊情况即可（所有位全为9）。
 *第一种做法跟第二种做法区别就是if-else的判断条件互换，效率竟然差这么多。
 */

#include <vector>
using namespace std;

/*
执行用时：4 ms, 在所有 C++ 提交中击败了65.38%的用户
内存消耗：8.6 MB, 在所有 C++ 提交中击败了96.36%的用户
*/

//*时间复杂度：O（n）
//*空间复杂度:O(1)
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int maxIndex = digits.size() - 1;
        ++digits[maxIndex];
        for (int i = maxIndex; i > 0; i--)
        {
            if (digits[i] == 10)
            {
                digits[i] = 0;
                ++digits[i - 1];
            }
            else
            {
                return digits;
            }
        }

        //*全为9的情况
        if (digits[0] == 10)
        {
            vector<int> newDigits(maxIndex + 2, 0); //*注意此处是加2
            newDigits[0] = 1;
            return newDigits;
        }
        return digits;
    }
};

/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：8.6 MB, 在所有 C++ 提交中击败了96.36%的用户
*/
//*时间复杂度：O（n）
//*空间复杂度:O(1)
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int maxIndex = digits.size() - 1;
        ++digits[maxIndex];
        for (int i = maxIndex; i > 0; i--)
        {
            if (digits[i] != 10) //*先判断不用进位直接返回效率会高很多
            {
                return digits;
            }
            else
            {
                //*进位
                digits[i] = 0;
                ++digits[i - 1];
            }
        }

        //*全为9的情况
        if (digits[0] == 10)
        {
            vector<int> newDigits(maxIndex + 2, 0); //*注意此处是加2
            newDigits[0] = 1;
            return newDigits;
        }
        return digits;
    }
};