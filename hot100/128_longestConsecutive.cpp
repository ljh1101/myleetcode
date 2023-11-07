#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;
        for (auto num : nums) {
            s.emplace(num);
        }
        int res = 0;
        for (auto num : s) {
            if (s.count(num - 1) == 0) {
                int currentNum = num + 1;
                int count = 1;

                while (s.count(currentNum)) {
                    ++currentNum;
                    ++count;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};