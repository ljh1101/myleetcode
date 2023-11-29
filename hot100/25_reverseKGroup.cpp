

#include <utility>
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int nums = 0;
        ListNode* p = head;
        while (p) {
            ++nums;
            p = p->next;
        }
        return reverseList(head, k, nums);
    }
    ListNode* reverseList(ListNode* head, int k, int& num)
    {
        if (num < k) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            --num;
        }
        head->next = reverseList(curr, k, num);
        return prev;
    }
};