#include <unordered_set>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode *low = head, *fast = head, *p = head;
        while (fast) {
            if (!fast->next)
                return nullptr;
            low = low->next;
            fast = fast->next->next;
            if (fast == low) {
                while (low != p) {
                    p = p->next;
                    low = low->next;
                }
                return low;
            }
        }
        return nullptr;
    }
};