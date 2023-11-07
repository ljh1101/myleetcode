#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();
        int count = 0;
        int sum = 0;
        string res = "";
        for (auto c : s) {
            if (c == '1') {
                ++count;
            }
        }
        if (count < k) {
            return "";
        }
        for (int i = 0; i < k; i++) {
            if (s[i] == '1') {
                ++sum;
            }
        }
        int i = 0, j = k - 1;
        while (j < n) {
            if (sum >= k) {
                int num = sum - k;
                while (1) {
                    if (s[i] == '0') {
                        ++i;
                    }
                    else {
                        if (num-- > 0) {
                            ++i;
                            --sum;
                        }
                        else {
                            break;
                        }
                    }
                }
                if (res == "") {
                    res = s.substr(i, j - i + 1);
                }
                else {
                    if (res.size() > j - i + 1) {
                        res = s.substr(i, j - i + 1);
                    }
                    else if (res.size() == j - i + 1) {
                        res = min(res, s.substr(i, j - i + 1));
                    }
                }
            }
            ++j;
            if (j <= n - 1) {
                sum += s[j] == '1' ? 1 : 0;
            }
        }
        return res;
    }
};