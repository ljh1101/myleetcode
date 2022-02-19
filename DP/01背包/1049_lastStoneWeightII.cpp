/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-Mo 06:14:20
 * @Last Modified by:   Liu Jiahui
 * @Last Modified time: 2022-02-Mo 06:14:20
 */

/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:
If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.
Return the smallest possible weight of the left stone. If there are no stones left, return 0.

Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
*/

/*
 *刚开始感觉可以用堆排序，贪心的策略，但是代第一个测试用例就不行，所以不行
 *dp的话，刚开始不知道怎么转化成动态规划的问题，看了题解，主要就是转化成01背包问题难想
 *难在抽象
 *具体思路是背包的最大承重为物品总重量除以二，找背包所能装的最大重量
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O（n*target）
    //空间复杂度：O（target）
    int lastStoneWeightII(vector<int> &stones)
    {
        int len = stones.size();
        int sum = 0, target;
        for (int i = 0; i < len; i++)
            sum += stones[i];
        target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < len; i++)
            for (int j = target; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);

        return sum - 2 * dp[target];
    }
};