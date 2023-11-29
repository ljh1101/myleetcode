#include <unordered_map>
#include <utility>

class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node* copyRandomList(Node* head)
    {
        if (!head) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> mymap;
        Node* p = head;
        Node* newList = new Node(0);
        Node* q = newList;
        while (p) {
            q->next = new Node(p->val);
            q = q->next;
            mymap.emplace(p, q);
            p = p->next;
        }
        p = head;
        q = newList->next;
        while (p) {
            q->random = p->random ? mymap.find(p->random)->second : nullptr;
            q = q->next;
            p = p->next;
        }
        return newList->next;
    }
};