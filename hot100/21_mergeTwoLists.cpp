/*
 * @Author: Liu Jiahui
 * @Date: 2022-08-18 21:29:33
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-18 22:13:13
 */
/*
将两个升序链表合并为一个新的 升序
链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* resNode = new ListNode();
        ListNode* p = resNode;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = list1 ? list1 : list2;

        return resNode->next;
    }
};