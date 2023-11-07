
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//还可通过快慢指针找中点
class Solution {
  public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* p = head;
        int n = 0;
        while (p) {
            ++n;
            p = p->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        for (int i = 0; i < n / 2; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (n % 2 != 0) {
            next = next->next;
        }
        for (int i = 0; i < n / 2; i++) {
            if (prev->val != next->val) {
                return false;
            }
            prev = prev->next;
            next = next->next;
        }
        return true;
    }
};