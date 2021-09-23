// Problem: https://leetcode.com/problems/lru-cache
// Author: github.com/ankuralld5999
// Time:
//    get: O(1)
//    put: O(1)
// Space: O(N)
class LRUCache {
private:
  list<pair<int, int>> data;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  int capacity;
public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!m.count(key)) return -1;
    data.splice(data.begin(), data, m[key]);
    m[key] = data.begin();
    return data.front().second;
  }

  void put(int key, int value) {
    if (get(key) == -1) {
      if (data.size() == capacity) {
        auto p = data.back();
        m.erase(p.first);
        data.pop_back();
      }
      data.emplace_front(key, value);
      m[key] = data.begin();
    } else data.front().second = value;
  }
};
