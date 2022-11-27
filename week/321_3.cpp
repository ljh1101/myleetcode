// 没做出来

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
    ListNode* removeNodes(ListNode* head)
    {
        ListNode h(1e6, head);
        while (1) {
            bool flag = true;
            ListNode* node = &h;
            ListNode* next = node->next;
            while (next->next != nullptr) {
                if (next->val < next->next->val) {
                    node->next = next->next;
                    next = node->next;
                    flag = false;
                }
                else {
                    node = node->next;
                    next = node->next;
                }
            }
            if(flag){
                return h.next;;
            }
        }
    }
};