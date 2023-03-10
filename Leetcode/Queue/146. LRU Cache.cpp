// Problem Link - https://leetcode.com/problems/lru-cache/

#define ll int
class LRUCache {
public:
    class node
    {
        public:
        ll key;
        ll val;
        node* next;
        node* prev;
        node(ll k, ll v)
        {
            key = k;
            val = v;
        }
    };
    node * head = new node(-1,-1);
    node * tail = new node(-1,-1);
    ll cap;
    unordered_map<ll, node*> m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode)
    {
        newNode->next = head->next;
        head->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
    }
    
    void deleteNode(node* delNode)
    {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    int get(int nKey) {
        if(m.count(nKey))
        {
            node* curNode = m[nKey];
            ll val = curNode->val;
            m.erase(nKey);
            deleteNode(curNode);
            addNode(curNode);
            m[nKey] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int nKey, int nValue) {
        if(m.count(nKey))
        {
            node* curNode = m[nKey];
            m.erase(nKey);
            deleteNode(curNode);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(nKey,nValue));
        m[nKey] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */