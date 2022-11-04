#include <vector>
using namespace std;

class Solution {
  public:
    int arraySign(vector<int>& nums)
    {
        int count = 0;
        for (auto num : nums) {
            if (num == 0) {
                return 0;
            }
            else if (num < 0) {
                ++count;
            }
        }
        return count % 2 == 0 ? 1 : -1;
    }
};