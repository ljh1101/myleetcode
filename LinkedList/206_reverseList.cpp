/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-20 13:39:59
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-20 15:35:36
 */

/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

/*
 *链表反转比较简单，第一种方法我用了三个指针，从链表尾部开始依次插入前面的节点
 *第二种方法是原地反转
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    //链表反转
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *prev = head, *curr = head->next, *last = head; //定义三个指针
        while (last->next)                                       //让last指针指向链表尾
            last = last->next;
        while (prev != last)
        {
            prev->next = last->next;
            last->next = prev;
            prev = curr;
            curr = curr->next;
        }
        return last;
    }

    //直接反转
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *prev = nullptr, *curr = head, *next; //定义三个指针
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
