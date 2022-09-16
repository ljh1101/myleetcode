

/*
给你一个只包含 '(' 和 ')'
的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/

#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s)
    {
        if (s.empty()) {
            return 0;
        }
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};