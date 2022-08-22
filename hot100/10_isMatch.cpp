/*
 * @Author: Liu Jiahui
 * @Date: 2022-08-21 18:01:03
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-21 20:41:43
 */

/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持
'.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
*/

#include <string>
#include <vector>
using namespace std;

// 被放弃的版本，直接匹配
class Solution {
  public:
    bool isMatch(string s, string p)
    {
        int s_len = s.length();
        int p_len = p.length();

        //* . 普通字符的下标
        vector<int> _ptr;
        vector<int> _dot;
        vector<int> _letter;
        for (int i = 0; i < p_len; i++) {
            if (p[i] == '*')
                _ptr.emplace_back(i);
            else if (p[i] == '.')
                _dot.emplace_back(i);
            else
                _letter.emplace_back(i);
        }

        if (_ptr.size() == 0) {
            if (p_len != s_len)
                return false;
            for (int i = 0; i < s_len; i++) {
                if (p[i] == '.')
                    continue;
                if (p[i] != s[i])
                    return false;
            }
            return true;
        }
        else {
            // 用来判断字符左侧是否有*
            vector<int> check(_letter.size() + 1, -1);
            int __ptr = 0, __letter = 0;
            while (__ptr < _ptr.size() && __letter < _letter.size()) {
                while (_ptr[__ptr++] < _letter[__letter]) {
                    check[__letter] = 1;
                }
                while (_ptr[__ptr] > _letter[__letter++]) {
                    check[__letter] = 0;
                }
            }
            if (__ptr < _ptr.size())
                check[__letter] = 1;
            else
                for (int i = __letter; i < _letter.size(); i++)
                    check[__letter] = 0;

            int _s = 0, _p = 0;
            if (_letter.size() != 0) {}
        }
    }
};

class Solution {
  public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        //这里i，j不是下标，而是代表第几个字符
        auto match = [&](int i, int j) {
            if (i == 0)
                return false;
            else if (p[j - 1] == '.')
                return true;
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];
                    if (match(i, j - 1))
                        dp[i][j] |= dp[i - 1][j];
                }
                else {
                    if (match(i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};