// Problem Link - https://leetcode.com/problems/lfu-cache/

#define ll int

struct Node
{
    ll key, value, cnt;
    Node* next;
    Node* prev;
    Node(ll k, ll v)
    {
        key = k;
        value = v;
        cnt = 1;
    }
};

struct List
{
    ll size;
    Node* head;
    Node* tail;
    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    
    void removeNode(Node* delNode)
    {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        size--;
    }
};

class LFUCache {
public:
    map<ll,Node*> keyNode;
    map<ll,List*> freqListMap;
    ll maxSizeCache;
    ll minFreq;
    ll curSize;
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    void updateFreqListMap(Node* node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq and freqListMap[node->cnt]->size==0)
            minFreq++;
        List* nextHigherFreqList = new List();
        if(freqListMap.count(node->cnt+1))
            nextHigherFreqList = freqListMap[node->cnt+1];
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.count(key))
        {
            Node* node = keyNode[key];
            ll val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0)
            return;
        if(keyNode.count(key))
        {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if(curSize==maxSizeCache)
            {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.count(minFreq))
                listFreq = freqListMap[minFreq];
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */