/*
 * @Author: Liu Jiahui
 * @Date: 2022-07-01 10:57:06
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-07-01 15:52:16
 */

/*
 *给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值
 *target  的那 两个 整数，并返回它们的数组下标。
 *你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 *你可以按任意顺序返回答案。
 */

#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> _map;
        for (int i = 0; i < nums.size(); i++) {
            if (_map.find(target - nums[i]) != _map.end()) {
                return {_map[target - nums[i]], i};
            }
            _map[nums[i]] = i;
        }
        return {};
    }
};