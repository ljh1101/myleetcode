#include <cstddef>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int, int> map;
        stack<int> st;
        for (int i = size2 - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!st.empty() && num > st.top()) {
                st.pop();
            }
            map.emplace(num, st.empty() ? -1 : st.top());
            st.emplace(num);
        }
        for (int i = 0; i < size1; i++) {
            nums1[i] = map[nums1[i]];
        }
        return nums1;
    }
};