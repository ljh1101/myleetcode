/*
 * @Author: Liu Jiahui
 * @Date: 2022-03-11 10:01:01
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-03-11 11:20:22
 */

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/

/*
*刚开始的做法像是回溯，每碰到重复的都要回去重新遍历，时间复杂度较高
*/
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // map做的，费时间空间
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, bool> dict;
        int num = 0, result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (dict.find(s[i]) == dict.end())
            {
                dict.emplace(s[i], true);
                ++num;
            }
            else
            {
                i = i - num;
                num = 0;
                dict.clear();
            }
            result = max(result, num);
        }
        return result;
    }

    // set做
    //时间复杂度：O(N)。
    //空间复杂度：O(∣Σ∣)，∣Σ∣是字符集的大小。
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> dict;
        int num = 0, result = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (i != 0)
            {
                dict.erase(s[i - 1]);
            }
            while (num < len && !dict.count(s[num]))
            {
                dict.insert(s[num]);
                ++num;
            }
            result = max(result, num - i);
        }
        return result;
    }
};