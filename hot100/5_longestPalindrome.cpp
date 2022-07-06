/*
 * @Author: Liu Jiahui
 * @Date: 2022-07-06 19:05:53
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-07-06 20:30:21
 */
/*
给你一个字符串 s，找到 s 中最长的回文子串。
*/

/*
看了思路写的，光想着从头开始检查，一直找不到切入点。
应该是以每个元素或相邻的两个元素为轴，向两侧检查，虽然没有这样没有用到已找到的回文串，没有达到最优
但也还算不错。
*/

#include <string>
using namespace std;

class Solution {
  public:
    void find(const string& s, string& res, int l, int r)
    {
        int len = s.length();
        string temp;
        while (l >= 0 && r < len) {
            if (s[l] != s[r]) {
                break;
            }
            --l;
            ++r;
        }
        temp = s.substr(l + 1, r - l - 1);
        res = res.length() < temp.length() ? temp : res;
    }
    string longestPalindrome(string s)
    {
        int len = s.length();
        if (len == 1) {
            return s;
        }
        string res;
        for (size_t i = 0; i < len - 1; i++) {
            find(s, res, i, i);
            find(s, res, i, i + 1);
        }
        return res;
    }
};
