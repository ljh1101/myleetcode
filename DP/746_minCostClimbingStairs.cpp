/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-24 11:04:12
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-24 22:53:18
 */

/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。
示例 1：
输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
*/

/*
 *过程不是很顺利，但好在独立写出来了
 *主要还是搞清楚怎么由前面两阶楼梯的最小花费得到当前楼梯的最小花费，要搞清楚公式
 */

#include <vector>
using namespace std;

class Solution
{
public:
    //最小花费爬楼梯
    int minCostClimbingStairs(vector<int> &cost)
    {
        int len = cost.size();
        vector<int> lowestCost(len + 1, 0);
        for (int i = 2; i <= len; i++)
        {
            int i_2 = lowestCost[i - 2] + cost[i - 2]; //从前两阶楼梯上来的花费
            int i_1 = lowestCost[i - 1] + cost[i - 1]; //从前一阶楼梯上来的花费
            lowestCost[i] = i_2 <= i_1 ? i_2 : i_1;
        }
        return lowestCost[len];
    }
};