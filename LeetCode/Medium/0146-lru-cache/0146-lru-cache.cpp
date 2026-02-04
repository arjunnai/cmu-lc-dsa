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
    int cap;
    Node* head;
    Node* tail;

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
            // first get node* from the map
            Node* temp = cache[key];
            // remove it from current spot
            removeNode(temp);
            // add it to front of list
            addNode(temp);
            // return value
            return temp->val;
            // update hashmap - (No action needed: pointer address is unchanged)
        }
        return -1;
    }

    void put(int key, int value) {
        // 2 scenarios
        // 1. update - key already exists
        if (cache.contains(key)) {
            // find the node
            Node* existing = cache[key];
            // update the value w new value
            existing->val = value;
            // remove old one from list
            removeNode(existing);
            // add to head of list since it becomes mru
            addNode(existing);
            return;
        }
        // 2. key is new
        Node* lru = tail->prev;
        if (cache.size() == cap) {
            // id the node to remove
            // get key from hashmap
            //  remove key from hashmap
            cache.erase(lru->key);
            // removenode from list
            removeNode(lru);
            // free memory
            delete lru;
        }
        // add new node
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        addNode(newNode);
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }
    void removeNode(Node* delNode) {
        Node* Ltemp = delNode->prev;
        Node* Rtemp = delNode->next;
        Ltemp->next = Rtemp;
        Rtemp->prev = Ltemp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */