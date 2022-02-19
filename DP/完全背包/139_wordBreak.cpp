/*
 * @Author: Liu Jiahui
 * @Date: 2022-02-18 10:11:52
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-02-18 11:27:11
 */

/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/

/*
 *能独立做出，还是很高兴的。这是一个关于字符串的问题，要比较的是字符串是否相等，这一点要能解决
 *然后就是找状态转移方程，搞清楚逻辑
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //时间复杂度：O(n^3),因为substr返回子串的副本是O(n)的复杂度（这里的n是substring的长度）
    //空间复杂度：O(n)
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.length();
        vector<bool> dp(len, false);
        dp[0] = true;
        for (int j = 1; j <= len; j++)
        {
            for (auto str : wordDict)
            {
                int strLen = str.length();
                if (strLen <= j && s.substr(j - strLen, strLen) == str)
                    dp[j] = dp[j] | dp[j - strLen]; //状态转移方程
            }
        }
        return dp[len];
    }
};