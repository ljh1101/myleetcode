/*
 * @Author: Liu Jiahui
 * @Date: 2022-07-05 19:18:52
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-07-05 20:18:14
 */

/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
和 nums2。请你找出并返回这两个正序数组的 中位数 。 算法的时间复杂度应该为 O(log
(m+n)) 。
*/

/*
不会做，抄答案做的，还是没太理解
*/

#include <vector>
using namespace std;

class Solution {
  public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (1) {
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            else if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);

            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 0) {
            return (getKthElement(nums1, nums2, totalLength / 2) +
                    getKthElement(nums1, nums2, totalLength / 2 + 1)) /
                   2.0;
        }
        else {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
    }
};
