#include <cstdint>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int>& nums)
    {
        int res = INT16_MIN;
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
            if (sum < num) {
                sum = num;
            }

            res = max(res, sum);
        }
        return res;
    }
};