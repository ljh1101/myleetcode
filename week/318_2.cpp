#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        int len = nums.size();
        long long res = 0;
        for (int i = 0; i < len - k + 1;) {
            unordered_map<int, int> map;
            long long sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += nums[j];
                auto pos = map.find(nums[j]);
                if (pos != map.end()) {
                    i = pos->second + 1;
                    sum = 0;
                    break;
                }
                map.emplace(nums[j], j);
            }
            if (sum != 0) {
                i++;
            }
            res = max(res, sum);
        }
        return res;
    }
};