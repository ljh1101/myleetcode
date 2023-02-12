#include <vector>
using namespace std;

class Solution {
  public:
    int maximumCount(vector<int>& nums)
    {
        int len = nums.size();
        int i = 0;
        for (; i < len; i++) {
            if (nums[i] >= 0) {
                break;
            }
        }
        int l = i;
        while (nums[i] == 0) {
            ++i;
        }
        return max(l, len - i);
    }
};