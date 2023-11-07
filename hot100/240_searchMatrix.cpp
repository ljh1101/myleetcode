#include <vector>
using namespace std;
//效率爆低
class Solution1 {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        while (i < m && i < n) {
            if (matrix[i][i] >= target) {
                int j = i;
                while (matrix[i][j] >= target || matrix[j][i] >= target) {
                    if (matrix[i][j] == target || matrix[j][i] == target) {
                        return true;
                    }
                    if (j-- == 0) {
                        break;
                    }
                }
                ++i;
                break;
            }
            ++i;
        }
        if (i < m) {
            for (int k = i; k < m; k++) {
                int j = n - 1;
                while (matrix[k][j] >= target) {
                    if (matrix[k][j] == target) {
                        return true;
                    }
                    if (j-- == 0) {
                        break;
                    }
                }
            }
        }
        if (i < n) {
            for (int k = i; k < n; k++) {
                int j = m - 1;
                while (matrix[j][k] >= target) {
                    if (matrix[j][k] == target) {
                        return true;
                    }
                    if (j-- == 0) {
                        break;
                    }
                }
            }
        }
        return false;
    }
};

//真他娘的天才
//搜索不一定从头开始，本题从右上角开始合适
//如果当前元素小于target，则x+1，本行不需要搜索了，本行所有元素都小于target
//如果当前元素大于target，则y-1，本列不需要搜索了，本列所有元素都大于target
class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            else if (matrix[x][y] < target) {
                ++x;
            }
            else {
                --y;
            }
        }
        return false;
    }
};