class FreqStack {
    unordered_map<int, int> freq; // each val -> count
    unordered_map<int, stack<int>>
        groups; // frequency -> stack of values at that freq
    int maxF = 0;

public:
    FreqStack() {}

    void push(int val) {
        freq[val]++;
        maxF = max(maxF, freq[val]);
        groups[freq[val]].push(val);
    }

    int pop() {
        int val = groups[maxF].top();
        groups[maxF].pop();
        freq[val]--;
        if (groups[maxF].empty())
            maxF--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */