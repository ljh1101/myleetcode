/*
 * @Author: Liu Jiahui 
 * @Date: 2021-10-22 22:13:35 
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2021-10-22 22:18:01
 */

//kmp算法的实现

#include <iostream>
using namespace std;

class Solution
{
public:
    //先计算next数组
    int *getnext(string substr)
    {
        int n = substr.length();
        int *next = new int[n];
        next[0] = 0;//初始化

        for (int i = 1, j = 0; i < n; i++)
        {
            while (j && substr[i] != substr[j])
                j = next[j - 1];
            if (substr[i] == substr[j])
                j++;
            next[i] = j;
        }
        return next;
    }

    int strStr(string haystack, string needle)
    {

        int m = haystack.length();
        int n = needle.length();
        if (n == 0) //特殊情况一定要放在头部 不然遇到特殊情况可能会出错
            return 0;

        int *next = getnext(needle);

        for (int i = 0, j = 0; i < m; i++)
        {
            while (j && haystack[i] != needle[j])
                j = next[j - 1];

            if (haystack[i] == needle[j])
                j++;
            if (j == n)
                return i - n + 1;
        }
        return -1;
    }
};

int main(void)
{
    string haystack = "abababc";
    string needle = "abc";
    Solution n = Solution();

    int aws = n.strStr(haystack, needle);
    cout << aws;
    cout << "asdasd";
    return 0;
}