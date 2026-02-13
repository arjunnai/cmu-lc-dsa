class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k = 0, int v = 0)
            : key(k), val(v), next(nullptr), prev(nullptr) {}
    };
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int cap;

public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    int get(int key) {
        if (cache.contains(key)) {
            Node* temp = cache[key];
            removeNode(temp);
            addNode(temp);
            return temp->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            Node* exist = cache[key];
            exist->val = value;
            removeNode(exist);
            addNode(exist);
            return;
        }
        if (cache.size() == cap) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            removeNode(lru);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        addNode(newNode);
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }

    void removeNode(Node* delNode) {
        Node* lTemp = delNode->prev;
        Node* rTemp = delNode->next;
        lTemp->next = rTemp;
        rTemp->prev = lTemp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */