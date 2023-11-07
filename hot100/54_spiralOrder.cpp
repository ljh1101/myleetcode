#include <iostream>
#include <vector>
using namespace std;

//模拟题真的烦 要搞清楚各种情况再下手 考虑好边界条件再做
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = m * n;
        int count = 0;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<int> res(sum);
        int i = 0, j = 0;
        while (count < sum) {
            for (i = left; i <= right; i++) {
                res[count++] = matrix[top][i];
            }
            ++top;
            for (j = top; j <= bottom; j++) {
                res[count++] = matrix[j][right];
            }
            --right;
            if (left <= right && top <= bottom) {
                for (i = right; i >= left; i--) {
                    res[count++] = matrix[bottom][i];
                }
                --bottom;
                for (j = bottom; j >= top; j--) {
                    res[count++] = matrix[j][left];
                }
                ++left;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    s.spiralOrder(a);
}