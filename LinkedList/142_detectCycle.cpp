/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-21 16:51:14
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-21 16:52:26
 */

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。
注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改 链表。
示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
*/

/*
 *刚开始认为哈希表不行，没想到哈希表可以直接存指针，又没想到双指针法。
 *自己写的话双指针法确实不容易想，我照着思路写过程也还有一些小错误。
 */

#include <unordered_set>
using namespace std;

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
    //寻找链表中环的入口（通过哈希表判断）
    //时间复杂度：O（n）
    //空间复杂度：O（n）
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *p = head;
        unordered_set<ListNode *> visited;
        while (p)
        {
            if (visited.count(p))
                return p;
            visited.insert(p);
            p = p->next;
        }
        return NULL;
    }

    //寻找链表中环的入口（双指针）
    //时间复杂度：O（n）
    //空间复杂度：O（1）
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *low = head, *fast = head, *p = head;
        while (fast)
        {
            if (!fast->next)
                return nullptr;
            low = low->next;
            fast = fast->next->next;
            if (fast == low)
            {
                while (low != p)
                {
                    p = p->next;
                    low = low->next;
                }
                return low;
            }
        }
        return nullptr;
    }
};