class MyHashSet {
    static const int BUCKETS = 769;
    vector<list<int>> table;

    int hash(int key) { return key % BUCKETS; }

public:
    MyHashSet() : table(BUCKETS) {}

    void add(int key) {
        if (!contains(key)) {
            auto& buck = table[hash(key)];
            buck.push_back(key);
        }
    }

    void remove(int key) {
        auto& buck = table[hash(key)];
        buck.remove(key);
    }

    bool contains(int key) {
        auto& buck = table[hash(key)];
        // return find(buck.begin(), buck.end(), key);
        for (int x : buck) {
            if (x == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */