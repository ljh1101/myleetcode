#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int>
    findIndices(vector<int>& nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();
        int b=n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp.emplace(nums[i], i);
        }
        auto i = mp.begin(), j = mp.end();
        while (n-->0) {
            if (j->first - i->first >= valueDifference &&
                abs(j->second - i->second) >= indexDifference) {
                return {i->second, j->second};
            }
            i++;
        }
        i=mp.begin();
        while (b-->0) {
            if (j->first - i->first >= valueDifference &&
                abs(j->second - i->second) >= indexDifference) {
                return {i->second, j->second};
            }
            j--;
        }

        return {-1, -1};
    }
};