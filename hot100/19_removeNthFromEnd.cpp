

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    //一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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