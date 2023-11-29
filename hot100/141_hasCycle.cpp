#include <unordered_set>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    bool hasCycle(ListNode* head)
    {
        std::unordered_set<ListNode*> set;
        ListNode* p = head;
        while (p) {
            if (set.count(p) != 0) {
                return true;
            }
            set.emplace(p);
            p = p->next;
        }
        return false;
    }
};

class Solution1 {
  public:
    bool hasCycle(ListNode* head)
    {
        if (!head || !head->next) {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};