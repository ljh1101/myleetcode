#include <algorithm>
#include <vector>
using namespace std;

//，首先要想到双指针要从两侧开始，考虑左指针移动还是右指针移动看移动后的面积大小没用
//要看那一侧是短板，毕竟如果短板不改变，那面积只会越来越小
class Solution {
  public:
    int maxArea(vector<int>& height)
    {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int sum = (j - i) * min(height[i], height[j]);
            if (height[i] < height[j]) {
                ++i;
            }  
            else {
                --j;
            }
            res = max(res, sum);
        }
        return res;
    }
};
