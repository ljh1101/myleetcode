/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-18 22:02:59
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-20 15:48:28
 */

/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
Example 1:
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
*/


/*
*排序后贪心，刚开始运行不正确，因为for循环表达式用逗号连接是以后面的表达式为主，这样数组会溢出。
*也可以从后向前遍历
*注意下面结论。
for（；表达式1，表达式2；）   则以条件2为主。
for（；表达式1&表达式2；）    则以先达到条件的表达式为主。
for（；表达式1|表达式2；）     则以后达到条件的表达式为主。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(nlogn)
    //空间复杂度：O(1)
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int maxContent = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0, j = 0; i < g.size() && j < s.size();)
        {
            if (g[i] > s[j])
                ++j;
            else
            {
                ++i;
                ++j;
                ++maxContent;
            }
        }
        return maxContent;
    }
};