/*
 * @Author: Liu Jiahui
 * @Date: 2022-08-17 21:35:10
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-17 22:12:56
 */

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto ss : s) {
            if (ss == '(' || ss == '{' || ss == '[') {
                st.emplace(ss);
            }
            else {
                if (st.empty())
                    return false;
                if (ss == ')' && st.top() == '(')
                    st.pop();
                else if (ss == '}' && st.top() == '{')
                    st.pop();
                else if (ss == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};