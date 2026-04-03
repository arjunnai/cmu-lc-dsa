class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> storage;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        storage[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (!storage.contains(key)) {
            return "";
        }
        auto& keyTime = storage[key];
        string ans = "";
        int l = 0, r = storage[key].size() - 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(keyTime[mid].second <= timestamp){
                l = mid + 1;
                ans = keyTime[mid].first;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */