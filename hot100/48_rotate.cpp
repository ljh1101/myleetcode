#include <vector>
using namespace std;

// 这种一般不是硬旋转，要找规律的
//矩阵转置挨个沿对角线交换就行
class Solution {
  public:
    void rotate(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m / 2; j++) {
                swap(matrix[i][j], matrix[i][m - j - 1]);
            }
        }
    }
};