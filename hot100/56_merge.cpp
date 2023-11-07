#include <algorithm>
#include <vector>
using namespace std;

//又没想到排序
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (start > res.back()[1]) {
                res.push_back({start, end});
            }
            else {
                res.back()[1] = max(end, res.back()[1]);
            }
        }
        return res;
    }
};
//比较函数不能写等于
//比较函数须满足：
//（1）两个关键字不能同时“小于等于”对方；如果k1“小于等于”k2，那么k2决不能“小于等于”k1。
//（2）如果k1“小于等于”k2，且k2“小于等于”k3，那么k1必须“小于等于”k3.
//（3）如果存在两个关键字，任何一个都不“小于等于”另一个，那我们称这两个关键字是“等价的”。如果k1“等价于”k2，且k2“等价于”k3，那么k1必须“等价于”k3。
class Solutionerr {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) -> bool { return a[0] <= b[0]; });//大于等于是不行的
        vector<vector<int>> res;
        res.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (start > res.back()[1]) {
                res.push_back({start, end});
            }
            else {
                res.back()[1] = max(end, res.back()[1]);
            }
        }
        return res;
    }
};