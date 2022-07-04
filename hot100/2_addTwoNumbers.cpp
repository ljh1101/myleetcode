/*
 * @Author: Liu Jiahui
 * @Date: 2022-07-01 15:56:16
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-07-01 17:27:24
 */

/*
给你两个 非空
的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

#include <cmath>
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

/*
刚开始先转int再相加，直接被教做人，现在直接相加，虽然跑过了，代码看起来还是不舒服
*/
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *l1_ptr = l1, *l2_ptr = l2;
        ListNode* result = new ListNode();
        ListNode* res_ptr = result;
        int x = 0;
        while (l1_ptr != nullptr || l2_ptr != nullptr) {
            if (l1_ptr != nullptr && l2_ptr != nullptr) {
                x += l1_ptr->val + l2_ptr->val;
                res_ptr->next = new ListNode(x % 10);

                l1_ptr = l1_ptr->next;
                l2_ptr = l2_ptr->next;
            }
            else {
                if (l1_ptr != nullptr) {
                    x += l1_ptr->val;
                    res_ptr->next = new ListNode(x % 10);
                    l1_ptr = l1_ptr->next;
                }
                else {
                    x += l2_ptr->val;
                    res_ptr->next = new ListNode(x % 10);
                    l2_ptr = l2_ptr->next;
                }
            }
            x /= 10;
            res_ptr = res_ptr->next;
        }
        if (x != 0) {
            res_ptr->next = new ListNode(x % 10);
        }
        return result->next;
    }
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *l1_ptr = l1, *l2_ptr = l2;
        ListNode* result = new ListNode();
        ListNode* res_ptr = result;
        int x = 0;  //进位位
        while (l1_ptr != nullptr || l2_ptr != nullptr || x != 0) {
            int m = l1_ptr == nullptr ? 0 : l1_ptr->val;  //两个被加数定义
            int n = l2_ptr == nullptr ? 0 : l2_ptr->val;
            x += m + n;
            res_ptr->next = new ListNode(x % 10);
            x /= 10;
            res_ptr = res_ptr->next;
            if (l1_ptr != nullptr)
                l1_ptr = l1_ptr->next;
            if (l2_ptr != nullptr)
                l2_ptr = l2_ptr->next;
        }

        return result->next;
    }
};