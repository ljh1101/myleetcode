#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

//滑动窗口+哈希 废了九牛二虎之力才做出来，知道用这个方法做，但是过程没捋清楚
//用数组代替哈希表比较的时候，注意消除无关元素的影响，本题中t中没有而s中有的字母就是
//此方法时间 空间消耗都比较高

class Solution {
  public:
    string minWindow(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        if (n1 < n2) {
            return "";
        }

        int need[128] = {0};
        for (auto tt : t) {
            ++need[tt];
        }
        int needcnt = n2;
        pair<int, int> pos(0, 0);
        int i = 0;
        for (int j = 0; j < n1; j++) {
            if (need[s[j]] > 0) {
                --needcnt;
            }
             --need[s[j]];

            if (needcnt == 0) {
                while (need[s[i]] < 0) {
                    ++need[s[i++]];
                }
                if (pos.second == 0 || pos.second > j - i + 1) {
                    pos.first = i;
                    pos.second = j - i + 1;
                }
                if (pos.second == n2) {
                    break;
                }
                ++need[s[i++]];
                ++needcnt;
            }
        }
        return s.substr(pos.first, pos.second);
    }
};

//优化思路一，维护的数组可由两个变成一个，只保留t_dict，从头开始遍历s每遇到一个字母，对应的t_dict--
//优化思路二，维护一个需要元素个数的变量，这样就不用每次都比较数组元素了
class Solution1 {
  public:
    bool cmp(const vector<int> a, const vector<int> b)
    {
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); i++) {
            if (b[i] == 0) {
                continue;
            }
            if (a[i] < b[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        if (n1 < n2) {
            return "";
        }

        vector<int> s_dict(128, 0);
        vector<int> t_dict(128, 0);
        for (int i = 0; i < n2; i++) {
            ++t_dict[t[i]];
            ++s_dict[s[i]];
        }
        if (cmp(s_dict, t_dict)) {
            return s.substr(0, n2);
        }

        pair<int, int> pos(0, 0);
        int i = 0;
        for (int j = n2; j < n1; j++) {
            ++s_dict[s[j]];
            if (cmp(s_dict, t_dict)) {
                while (t_dict[s[i]] == 0 || s_dict[s[i]] > t_dict[s[i]]) {
                    --s_dict[s[i++]];
                }
                if (pos.second == 0 || pos.second > j - i + 1) {
                    pos.first = i;
                    pos.second = j - i + 1;
                }
                if (pos.second == n2) {
                    break;
                }
                --s_dict[s[i++]];
            }
        }
        return s.substr(pos.first, pos.second);
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC");
}