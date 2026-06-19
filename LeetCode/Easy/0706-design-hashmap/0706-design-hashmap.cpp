class MyHashMap {
public:
    vector<list<pair<int, int>>> buckets;
    int size;
    MyHashMap() {
        size = 1e4;
        buckets.resize(size);
    }

    void put(int key, int value) {
        int bucketno = key % size;

        // chain is the linkedlist chaining
        auto& chain = buckets[bucketno];
        for (auto& it : chain) {
            // it.first = key
            // it.second = value;
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }

    int get(int key) {
        int bucketno = key % size;

        // chain is the linkedlist chaining
        auto& chain = buckets[bucketno];
        if (chain.empty())
            return -1;
        for (auto& it : chain) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int bucketno = key % size;

        // chain is the linkedlist chaining
        auto& chain = buckets[bucketno];
        // for(auto& it: chain){
        for (auto it = chain.begin(); it != chain.end(); it++) {
            // not it.first because it is a pointer
            if (it->first == key) {
                // erase takes a pointer but it is a pair{a, b}
                chain.erase(it);
                return;
            }
        }
    }
};

// brute force
//  class MyHashMap {
//  public:
//      vector<int> vec;
//      int size;
//      MyHashMap() {
//          size = 1e6+1;
//          vec.resize(size);
//          fill(begin(vec), end(vec), -1);
//      }

//     void put(int key, int value) {
//         vec[key] = value;
//     }

//     int get(int key) {
//         return vec[key];
//     }

//     void remove(int key) {
//         vec[key] = -1;
//     }
// };

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */