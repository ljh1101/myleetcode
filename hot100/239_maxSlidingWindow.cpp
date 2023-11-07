#include <algorithm>
#include <deque>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// 一个方法都想不出来，不管是nlogn的优先队列还是n的单调队列
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> dq;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> res = {nums[dq.front()]};
        for (int i = k; i < nums.size(); i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (dq.front() <= i - k) {
                dq.pop_front();
            }
            res.emplace_back(nums[dq.front()]);
        }
        return res;
    }
};