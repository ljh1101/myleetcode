/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-18 11:04:48
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-18 12:32:19
 */

/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 
示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
*/


/*
*比较简单，就是要考虑一开始就要删除的情况，或者加个头节点
*加头节点判断next->next->val代码会更简洁，就不用prev了;
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

//时间复杂度：O（n）
//空间复杂度：O（1）

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
        {
            return head;
        }
        ListNode *prev, *next = head;    //两个指针
        while (next && next->val == val) //先解决第一个元素就要删除的情况
        {
            ListNode *p = next;
            next = next->next;
            head = next;
            delete p;
        }

        while (next)
        {
            if (next->val != val)
            {
                prev = next;
                next = next->next;
            }
            else
            {
                ListNode *p = next;
                next = next->next;
                prev->next = next;
                delete p;
            }
        }
        return head;
    }
};

/*
*加头节点版
*/

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;
        ListNode *h = new ListNode(0,head);//加上头指针做辅助
        ListNode *prev = h;
        while (prev->next)
        {
            if (prev->next->val != val)
                prev = prev->next;
            else
            {
                ListNode *p = prev->next;
                prev->next =  prev->next->next;
                delete p;
            }
        }
        return h->next;
    }
};