/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-21 10:39:08
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-21 11:50:03
 */

/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
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
    //一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
    ListNode *swapPairs(ListNode *head)
    {
        if (!head||!head->next)
            return head;
        ListNode *curr1 = head, *curr2 = head->next, *next; //定义四个指针
        ListNode *result = head->next;
        while (curr2)
        {
            next = curr2->next;
            if (next && next->next)
            {
                curr1->next = next->next;
                curr2->next = curr1;
                curr1 = next;
                curr2 = curr1->next;
            }
            else
            {
                curr1->next = next;
                curr2->next = curr1;
                break;
            }
        }
        return result;
    }
};