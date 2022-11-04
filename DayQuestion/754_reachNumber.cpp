#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
  public:
    int reachNumber(int target)
    {
        int abs_target = abs(target);
        int count = 0;
        int i = 0;
        while (count < abs_target || (count - abs_target) % 2 != 0) {
            ++i;
            count += i;
        }
        return i;
    }
};