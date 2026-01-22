class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>>> ump;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!ump.contains(key)){
            return "";
        }
        auto& pairs = ump[key];
        string res = "";
        int l = 0, r = ump[key].size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(pairs[mid].second <= timestamp){
                res = pairs[mid].first;
                l = mid + 1;
            }else if(pairs[mid].second > timestamp){
                r = mid - 1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */