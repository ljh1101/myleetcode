#include <vector>
using namespace std;

class Solution {
  public:
    int gcd(int a, int b)
    {
        return b > 0 ? gcd(b, a % b) : a;
    }
    int subarrayLCM(vector<int>& nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            long long int lcm = nums[i];
            for (int j = i; j < nums.size(); j++) {
                lcm = lcm * nums[j] / gcd(lcm, nums[j]);
                if (lcm == k) {
                    ++count;
                }
                else if (k % lcm != 0) {
                    break;
                }
            }
        }
        return count;
    }
};