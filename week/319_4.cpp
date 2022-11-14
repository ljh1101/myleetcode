#include <string>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int
    find(const string& s, unordered_set<int>& set, const int& k, int l, int r)
    {
        int len = s.length();
        int count = 0;
        while (l >= 0 && r < len) {
            if (s[l] != s[r]) {
                break;
            }
            if (set.count(l) != 0 || set.count(r) != 0) {
                break;
            }
            if (r - l + 1 >= k) {
                set.emplace(l);
                set.emplace(r);
                ++count;
                break;
            }
            --l;
            ++r;
        }
        return count;
    }

    int maxPalindromes(string s, int k)
    {
        int len = s.length();
        int count = 0;
        unordered_set<int> set;
        for (int i = 0; i < len; i++) {
            count += find(s, set, k, i, i);
            if (i < len - 1) {
                count += find(s, set, k, i, i + 1);
            }
        }
        return count;
    }
};