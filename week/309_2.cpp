#include <cmath>
#include <vector>
using namespace std;

class Solution {
  public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        unsigned int distance = abs(endPos - startPos);
        if (distance > k || (k - distance) % 2 == 1) {
            return 0;
        }
        int res = 1;
        for (int i = distance + 2; i < k + 1; i += 2) {
            res *= i;
        }
        return res;
    }
};