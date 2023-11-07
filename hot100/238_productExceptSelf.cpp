#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> pre(n, 1), suf(n, 1);
        vector<int> res(n);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = n - 1; i > 0; i--) {
            suf[i - 1] = suf[i] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            res[i] = pre[i] * suf[i];
        }
        return res;
    }
};