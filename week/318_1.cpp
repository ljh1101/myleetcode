#include <iterator>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> applyOperations(vector<int>& nums)
    {
        int len = nums.size();
        int count = 0;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        for (vector<int>::iterator iter = nums.begin(); iter < nums.end();) {
            if (*iter == 0) {
                nums.erase(iter);
                ++count;
            }
            else {
                ++iter;
            }
        }
        nums.insert(nums.end(), count, 0);
        return nums;
    }
};