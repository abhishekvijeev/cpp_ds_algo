#include <bits/stdc++.h>

using namespace std;

class HashMap
{
    public:

    HashMap() {
        table.resize(TABLE_SIZE);
    }
    
    void put(int key, int value) {
        int hash = key % TABLE_SIZE;
        list<pair<int, int>>& row = table[hash];
        for (auto it = row.begin(); it != row.end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        row.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int hash = key % TABLE_SIZE;
        list<pair<int, int>>& row = table[hash];
        for (auto it = row.begin(); it != row.end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int hash = key % TABLE_SIZE;
        list<pair<int, int>>& row = table[hash];
        for (auto it = row.begin(); it != row.end(); it++) {
            if (it->first == key) {
                row.erase(it);
                return;
            }
        }
    }

    private:

    vector<list<pair<int, int>>> table;
    const int TABLE_SIZE = 10000;
};

int main()
{
    return 0;
}