#include <string>
#include <vector>
using namespace std;

//字符串s依次遍历，每遍历一个字符串p对应的字母减少一个，这种不定量的分析方式很复杂，容易错，条件多
//应当参考答案里的那样，维护两个数组，固定一个p长度的窗口，依次对比即可
class Solution {
  public:
    vector<int> findAnagrams(string s, string p)
    {
        int s_len = s.size(), p_len = p.size();
        if (s_len < p_len) {
            return vector<int>();
        }
        vector<int> res;
        vector<int> dictp(26, 0);
        vector<int> dicts(26, 0);
        for (int i = 0; i < p_len; i++) {
            dictp[p[i] - 'a']++;
            dicts[s[i] - 'a']++;
        }
        if (dictp == dicts) {
            res.emplace_back(0);
        }
        for (int j = 0; j < s_len - p_len; j++) {
            dicts[s[j] - 'a']--;
            dicts[s[j + p_len] - 'a']++;
            if (dictp == dicts) {
                res.emplace_back(j + 1);
            }
        }
        return res;
    }
};