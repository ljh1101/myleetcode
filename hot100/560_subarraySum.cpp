#include <unordered_map>
#include <vector>
using namespace std;
//前缀和+哈希优化
class Solution {
  public:
    int subarraySum(vector<int>& nums, int k)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int num : nums) {
            sum += num;
            if (mp.count(sum - k) > 0) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};