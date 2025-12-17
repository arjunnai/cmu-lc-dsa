class MinStack {
public:
    vector<int> main_st;
    vector<int> min_st;
    MinStack() {}

    void push(int val) {
        main_st.push_back(val);
        if (min_st.empty()) {
            min_st.push_back(val);
        } else {
            min_st.push_back(min(min_st.back(), val));
        }
    }

    void pop() {
        if (!main_st.empty()) {
            main_st.pop_back();
        } 
        if (!min_st.empty()) {
            min_st.pop_back();
        }
    }

    int top() {
        if (!main_st.empty()) {
            return main_st.back();
        } else {
            return {};
        }
    }

    int getMin() {
        if (!min_st.empty()) {
            return min_st.back();
        } else {
            return {};
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
