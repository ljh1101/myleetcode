/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-21 11:51:40
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-21 16:22:07
 */

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
*/

/*
*比较简单的题目，刚开始还没写出来， while (p = p->next;)，是判断 p->next，刚开始理解错。
*if里面的刚开始写了赋值语句还没看出来。
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
    //一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 0, index;
        ListNode *p = head;
        while (p) //计算链表长度
        {
            p = p->next;
            ++len;
        }
        index = len - n;
        if (index == 0) //特殊情况处理
        {
            p = head->next;
            delete head;
            return p;
        }
        p = head;
        for (int i = 1; i < index; i++) //让指针指向被删除节点的前一个
            p = p->next;
        ListNode *deleteNode = p->next;
        p->next = deleteNode->next;
        delete deleteNode;
        return head;
    }
};
