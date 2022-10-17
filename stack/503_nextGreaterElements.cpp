#include <cstddef>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> res(size, -1);
        stack<int> st;
        for (int i = 0; i < size * 2; i++) {
            int num = nums[i % size];
            while (!st.empty() && num > nums[st.top()]) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < size) {
                st.emplace(i);
            }
        }
        return res;
    }
};