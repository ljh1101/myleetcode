#include <type_traits>
#include <unordered_map>

using namespace std;

struct DLinkedNode
{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr)
    {
    }
};

class LRUCache {
    unordered_map<int, DLinkedNode*> mp;
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity;
    int size;

  public:
    LRUCache(int capacity) : capacity(capacity), size(0)
    {
        this->head = new DLinkedNode();
        this->tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (this->mp.count(key) == 0) {
            return -1;
        }
        moveToHead(this->mp[key]);
        return this->mp[key]->value;
    }

    void put(int key, int value)
    {
        if (this->mp.count(key) != 0) {
            this->mp[key]->value = value;
            moveToHead(this->mp[key]);
        }
        else {
            DLinkedNode* node = new DLinkedNode(key, value);
            if (this->size < this->capacity) {
                moveToHead(node);
                this->mp.emplace(key,node);
                ++this->size;
            }
            else {
                moveToHead(node);
                this->mp.emplace(key,node);
                DLinkedNode* node = tail->prev;
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
                this->mp.erase(node->key);
                delete node;
            }
        }
    }

    void moveToHead(DLinkedNode* node)
    {
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
};