/*
 * @Author: Liu Jiahui
 * @Date: 2022-01-19 15:09:37
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-01-19 15:22:15
 */

/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
*/

/*
*刚开始没搞清节点与链表的关系，上去直接对节点操作，有些地方写不出来
*这一点明白了，实现就比较简单了
*/

class MyLinkedList
{
private:
    struct LinkedListNode
    {
        int val;
        LinkedListNode *next;
        LinkedListNode(int val) : val(val), next(nullptr){};
        LinkedListNode(int x, LinkedListNode *next) : val(x), next(next) {}
    } * head;
    int size;

public:
    //构造函数，无参数,创建一个新节点。
    MyLinkedList()
    {
        this->head = new LinkedListNode(0);
        this->size = 0;
    }

    // get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
    int get(int index)
    {
        LinkedListNode *p = this->head->next;
        int i = 0; //遍历的下标
        if (index >= this->size)
            return -1;
        while (p)
        {
            if (i == index)
                break;
            p = p->next;
            ++i;
        }
        return p->val;
    }

    // addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
    void addAtHead(int val)
    {
        LinkedListNode *newNode = new LinkedListNode(val, this->head->next);
        this->head->next = newNode;
        ++this->size;
    }

    // addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
    void addAtTail(int val)
    {
        LinkedListNode *node = new LinkedListNode(val);
        LinkedListNode *p = this->head;
        while (p->next)
            p = p->next;
        p->next = node;
        ++this->size;
    }

    // addAtIndex(index,val)：在链表中的第index个节点之前添加值为 val的节点。如果index等于链表的长度，则该节点将附加到链表的末尾。如果index大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    void addAtIndex(int index, int val)
    {
        if (index > this->size)
            return;
        LinkedListNode *node = new LinkedListNode(val);
        LinkedListNode *p = this->head;
        if (index <= 0)
        {
            node->next = p->next;
            p->next = node;
            ++this->size;
        }
        else if (index == this->size)
        {
            while (p->next)
                p = p->next;
            p->next = node;
            ++this->size;
        }

        else
        {
            for (int i = 0; i < index; i++)
                p = p->next;
            node->next = p->next;
            p->next = node;
            ++this->size;
        }
    }

    // deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
    void deleteAtIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            LinkedListNode *p = this->head;
            for (int i = 0; i < index; i++)
                p = p->next;
            LinkedListNode *deleteNode = p->next;
            p->next = p->next->next;
            delete deleteNode;
            --this->size;
        }
    }
};