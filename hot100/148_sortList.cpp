#include <algorithm>
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
    ListNode* sortList(ListNode* head)
    {
        if (!head) {
            return nullptr;
        }
        ListNode* start = new ListNode(0, head);
        ListNode* end = head;
        ListNode* p = head->next;

        while (p) {
            if (p->val < end->val) {
                ListNode* prev = start;
                ListNode* q = prev->next;

                do {
                    if (p->val < q->val) {
                        end->next = p->next;
                        p->next = q;
                        prev->next = p;
                        break;
                    }
                    q = q->next;
                    prev = prev->next;
                } while (q != end->next);
            }
            else {
                end = end->next;
            }
            p = end->next;
        }
        return start->next;
    }
};

class Solution1 {
  public:
    ListNode* sortList(ListNode* head)
    {
        if (!head) {
            return nullptr;
        }
        vector<int> arr(1, head->val);
        ListNode* p = head;
        while ((p = p->next)) {
            arr.emplace_back(p->val);
        }
        sort(arr.begin(), arr.end());
        p = head;
        for (auto a : arr) {
            p->val = a;
            p = p->next;
        }
        return head;
    }
};

class Solution2 {
  public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;
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

int main()
{
    ListNode* a = new ListNode(3, nullptr);
    ListNode* b = new ListNode(1, a);
    ListNode* c = new ListNode(2, b);
    ListNode* d = new ListNode(4, c);
    Solution* ff = new Solution();
    ff->sortList(d);
    return 0;
}