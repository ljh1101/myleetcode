#include <set>
#include <vector>
using namespace std;

//让所有元素归位，就是数组的值和下标相等，遍历完一遍后，数组元素和下标不相等的元素即为答案
//若数组中所有元素都没问题，则返回n+1
//让元素归为采用了交换的思想，注意交换完一次后当前的元素一定要小于等于0或者大于n，否则要继续交换
//不然会导致当前元素未到指定位置导致答案错误
class Solution {
  public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        nums.emplace_back(-1);
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]] != nums[i]) {
                swap(nums[nums[i]], nums[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n + 1;
    }
};

//自己想出的解决方法，时间复杂度和空间复杂度都不满足要求
class Solution1 {
  public:
    int firstMissingPositive(vector<int>& nums)
    {
        set<int> myset;
        for (auto& num : nums) {
            if (num > 0) {
                myset.emplace(num);
            }
        }
        if (*myset.begin() != 1) {
            return 1;
        }
        for (auto& s : myset) {
            if (myset.count(s + 1) == 0) {
                return s + 1;
            }
        }
        return *myset.end() + 1;
    }
};