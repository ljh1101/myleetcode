#include <algorithm>
#include <vector>
using namespace std;

//固定一个找两个，同时要注意去重
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {  //去重
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                }
                else if (sum > 0) {
                    --k;
                }
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1])  //去重
                        j++;
                    while (j < k && nums[k] == nums[k + 1])  //去重
                        k--;
                }
            }
        }
        return res;
    }
};
