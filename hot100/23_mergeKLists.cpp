#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeSort(lists, 0, lists.size() - 1);
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int start, int end)
    {
        int mid = (start + end) / 2;
        if (start < end) {
            ListNode* left = mergeSort(lists, start, mid);
            ListNode* right = mergeSort(lists, mid + 1, end);
            return merge(left, right);
        }
        return lists[start];
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (left && right) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            }
            else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left ? left : right;
        return res->next;
    }
};