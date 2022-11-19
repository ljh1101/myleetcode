#include <vector>
using namespace std;

class Solution {
  public:
    int largestAltitude(vector<int>& gain)
    {
        int sum = 0, res = 0;
        for (int g : gain) {
            sum += g;
            res = sum > res ? sum : res;
        }
        return res;
    }
};