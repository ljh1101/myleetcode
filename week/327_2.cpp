#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
  public:
    long long maxKelements(vector<int>& nums, int k)
    {
        long long count = 0;
        for (int i = 0; i < k; i++) {
            sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
            count += static_cast<long long>(nums[0]);
            nums[0] = ceil(nums[0] / 3.0);
        }
        return count;
    }
};