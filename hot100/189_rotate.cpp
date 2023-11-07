#include <algorithm>
#include <vector>
using namespace std;

//这种反转方法真想不到
class Solution {
  public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

class Solution1 {
  public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> arr(nums.end() - k, nums.end());
        for (int i = 0; i < n - k; i++) {
            arr.emplace_back(nums[i]);
        }
        nums.assign(arr.begin(), arr.end());
    }
};