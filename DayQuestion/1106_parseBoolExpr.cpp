/*
 * @Author: Liu Jiahui
 * @Date: 2022-11-05 15:39:48
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-11-05 16:47:45
 */
 #include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    bool parseBoolExpr(string expression)
    {
        bool flag;
        stack<char> st1, st2;
        for (char s : expression) {
            if (s == '|' || s == '&' || s == '!') {
                st1.emplace(s);
            }
            else if (s == 't' || s == 'f' || s == '(') {
                st2.emplace(s);
            }
            else if (s == ')') {
                flag = st2.top() == 't' ? true : false;
                while (!st2.empty() && st2.top() != '(') {
                    if (!st1.empty() && st1.top() == '|') {
                        flag |= st2.top()=='t'?true:false;
                    }
                    else if (!st1.empty() && st1.top() == '&') {
                        flag &= st2.top()=='t'?true:false;
                    }
                    else if (!st1.empty() && st1.top() == '!') {
                        flag = !(st2.top()=='t'?true:false);
                    }
                    st2.pop();
                }
                st2.pop();
                st1.pop();
                char t = flag ? 't' : 'f';
                st2.emplace(t);
            }
        }
        return st2.top() == 't' ? true : false;
    }
};

int main(){
  Solution s;
  string a = "!(f)";
  bool res = s.parseBoolExpr(a);
  cout<<res;
}