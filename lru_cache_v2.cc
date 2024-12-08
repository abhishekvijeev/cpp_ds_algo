#include <bits/stdc++.h>

using namespace std;

template <typename TKey, typename TValue>
class LRUCache
{
    public:

    LRUCache(): capacity{DEFAULT_CAPACITY} {}

    LRUCache(size_t capacity): capacity{capacity} { }

    // When a key is looked up, it should become most-recently-used
    bool Lookup(TKey key, TValue* value)
    {
        auto it = hash_table.find(key);
        if (it == hash_table.end()) {
            return false;
        }
        *value = it->second;

        

        return true;
    }

    // If the cache is full, evict the least recently used entry
    void Insert(TKey key, TValue value)
    {
        if (hash_table.size() == capacity) {
            TKey lru_key = recency_list.back();
            recency_list.pop_back();
            hash_table.erase(lru_key);
        }
        recency_list.emplace_front(key);
        hash_table[key] = make_pair(recency_list.begin(), value);
    }


    bool Remove(TKey key)
    {
        if (hash_table.find(key) == hash_table.end()) {
            return false;
        }
        hash_table.erase(key);
        return true;
    }

    private:

    unordered_map<TKey, pair<typename list<TKey>::iterator, TValue>> hash_table;
    list<TKey> recency_list;
    size_t capacity;
    const size_t DEFAULT_CAPACITY = 10;
};

int main()
{
    LRUCache<int, int> c;
    return 0;
}