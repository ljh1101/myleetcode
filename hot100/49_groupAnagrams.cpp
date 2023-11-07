#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 没有想到先把字符串排序
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<string> strs_copy = strs;
        unordered_map<string, int> map;
        vector<vector<string>> res;
        int n = 0;

        for (string& str : strs_copy) {
            sort(str.begin(), str.end());
        }
        for (int i = 0; i < strs.size(); i++) {
            if (map.count(strs_copy[i]) == 0) {
                map.emplace(strs_copy[i], n++);
                res.emplace_back(vector<string>(1, strs[i]));
            }
            else {
                res[map[strs_copy[i]]].emplace_back(strs[i]);
            }
        }
        return res;
    }
};

class Solution1 {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        for (auto it = map.begin(); it != map.end(); ++it) {
            res.emplace_back(it->second);
        }
        return res;
    }
};