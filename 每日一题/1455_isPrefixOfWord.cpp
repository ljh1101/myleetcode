/*
 * @Author: Liu Jiahui
 * @Date: 2022-08-21 16:35:48
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-21 17:22:22
 */

/*
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用
单个空格 分隔的单词组成。 请你检查检索词 searchWord 是否为句子 sentence
中任意单词的前缀。 如果 searchWord 是某一个单词的前缀，则返回句子 sentence
中该单词所对应的下标（下标从 1 开始）。 如果 searchWord
是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord
不是任何单词的前缀，则返回 -1 。 字符串 s 的 前缀 是 s 的任何前导连续子字符串。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        vector<string> word = spilt(sentence, ' ');
        for (int i = 0; i < word.size(); i++) {
            if (startswith(word[i], searchWord))
                return i + 1;
        }
        return -1;
    }

    vector<string> spilt(string str, char sp)
    {
        str += sp;
        int size = str.length();
        vector<string> res;
        int len = 0;
        for (int i = 0; i < size; i++) {
            if (str[i] == sp) {
                res.emplace_back(str.substr(i - len, len));
                len = 0;
            }
            else
                ++len;
        }
        return res;
    }
    bool startswith(string str, string start)
    {
        int str_len = str.length();
        int start_len = start.length();
        if (str_len < start_len)
            return false;
        for (int i = 0; i < start_len; i++) {
            if (str[i] != start[i])
                return false;
        }
        return true;
    }
};