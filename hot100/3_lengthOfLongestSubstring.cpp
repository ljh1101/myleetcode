/*
 * @Author: Liu Jiahui
 * @Date: 2022-07-04 20:06:28
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-07-04 20:50:04
 */

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/

/*
做过一次，再做还是只会用笨方法
第二种方法是滑动窗口，左侧窗口每次走一步，每走一步就把前面的元素从set里面删掉，然后每走一步向后遍历，直到遇到重复元素。
*/

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0, temp = 0;
        unordered_set<char> dict;
        for (size_t i = 0; i < s.length(); i++) {
            if (dict.find(s[i]) == dict.end()) {
                dict.emplace(s[i]);
                ++temp;
            }
            else {
                i = i - temp;
                temp = 0;
                dict.clear();
            }
            result = max(result, temp);
        }
        return result;
    }
};

class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        size_t fast = 0, result = 0;
        unordered_set<char> dict;
        for (size_t low = 0; low < s.length(); low++) {
            while (fast < s.length() && dict.count(s[fast]) == 0) {
                dict.emplace(s[fast]);
                ++fast;
            }
            dict.erase(s[low]);
            result = max(result, fast - low);
        }
        return result;
    }
};