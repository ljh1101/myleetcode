#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }

        int i = 0, j = n - 1;
        int left = 0, right = 0;
        int res = 0;

        while (i < j) {
            left = max(left, height[i]);
            right = max(right, height[j]);
            if (left < right) {
                res += (left - height[i]);
                ++i;
            }
            else {
                res += (right - height[j]);
                --j;
            }
        }
        return res;
    }
};