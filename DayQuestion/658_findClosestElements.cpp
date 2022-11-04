/*
 * @Author: Liu Jiahui
 * @Date: 2022-08-25 19:23:46
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-25 20:17:14
 */

/*
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近
x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。 整数 a 比整数 b
更接近 x 需要满足： |a - x| < |b - x| 或者 |a - x| == |b - x| 且 a < b
*/

#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int n = arr.size();
        int location = binarySerach(arr, x);
        int l = location - k >= 0 ? location - k : 0;
        int r = location + k < n ? location + k : n - 1;
        while (true) {
            if (r - l + 1 == k) 
                return vector<int>(arr.begin()+l,arr.begin()+r+1);
            if (x - arr[l] > arr[r] - x)
                ++l;
            else
                --r;
        }
    }

    int binarySerach(vector<int>& arr, int num)
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num == arr[mid])
                return mid;
            else if (num < arr[mid])
                r = mid - 1;
            else if (num > arr[mid])
                l = mid + 1;
        }
        return (l + r) / 2;
    }
};