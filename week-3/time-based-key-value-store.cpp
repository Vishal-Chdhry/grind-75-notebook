class TimeMap {
 public:
  unordered_map<string, vector<pair<int, string>>> table;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    table[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto it = upper_bound(
        begin(table[key]), end(table[key]), pair<int, string>(timestamp, ""),
        [](const pair<int, string>& a, const pair<int, string>& b) {
          return a.first < b.first;
        });
    return it == table[key].begin() ? "" : prev(it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */