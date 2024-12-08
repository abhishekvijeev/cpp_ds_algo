
#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
    public:
    
    LRUCache(size_t capacity): capacity(capacity) { }

    bool Lookup(int key, int* value)
    {
        auto it = hash_table.find(key);
        if (it == hash_table.end()) {
            return false;
        }
        // *value = it->second;

        // Key has just been accessed - move it to the front
        auto key_position = it->second.first;
        recency_list.erase(key_position);
        recency_list.emplace_front(key);
        it->second.first = recency_list.begin();

        return true;
    }

    void Insert(int key, int value)
    {
        auto it = hash_table.find(key);
        if (it == hash_table.end()) {

            if (hash_table.size() == capacity) {
                int lru_key = recency_list.back();
                hash_table.erase(lru_key);
                recency_list.pop_back();
            }

            recency_list.emplace_front(key);
            hash_table[key] = {recency_list.begin(), value};
        }
        else {
            // Make this key the most recently used
            auto key_position = it->second.first;
            recency_list.erase(key_position);
            recency_list.emplace_front(key);
            it->second.first = recency_list.begin();
        }
    }

    bool Remove(int key)
    {
        auto it = hash_table.find(key);
        if (it == hash_table.end()){
            return false;
        }
        hash_table.erase(key);
        return true;
    }

    private:

    size_t capacity;
    unordered_map<int, pair<list<int>::iterator, int>> hash_table; // serves O(1) lookups 
    list<int> recency_list; // serves O(1) update to a key's recency - doing this update requires deletion from the recency list
};

int main()
{
    // LRUCache cache(10);
    // cache.Insert(100, 1);
    // cache.Insert(200, 2);
    // cache.Insert(300, 3);

    // cache.Insert(100, 2);
    list<int> l;
    l.emplace_back(10);
    auto it = l.begin();
    printf("%d\n", *it);
    l.emplace_back(20);
    printf("%d\n", *it);
    return 0;
}