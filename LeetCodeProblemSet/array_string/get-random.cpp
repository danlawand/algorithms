#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    int counter;
    unordered_map<int, int> ht;
    vector<int> keys;

public:
    RandomizedSet() {
        counter = 0;    
        srand(42);
    }

    bool insert(int val) {
        const bool a = ht.insert({val, 1}).second;
        if (!a) { return 0; }
        keys.push_back(val);
        counter++;
        return 1;
    }
    
    bool remove(int val) {
        size_t a = ht.erase(val);
        if (a == 0) { return 0; }
        keys.erase(std::remove(keys.begin(), keys.end(), val), keys.end());
        counter--;
        return 1;
    }
    
    int getRandom() {
        int randomValue = rand() % (counter);
        return keys[randomValue];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << "Insert 1 " << (obj->insert(1) ? "Succeed" : "Failed") << endl;
    cout << "Remove 2 " << (obj->remove(2) ? "Succeed" : "Failed") << endl;
    cout << "Insert 2 " << (obj->insert(2) ? "Succeed" : "Failed") << endl;
    cout << "GetRandom " << obj->getRandom() << endl;
    cout << "Remove 1 " << (obj->remove(1) ? "Succeed" : "Failed") << endl;
    cout << "Insert 2 " << (obj->insert(2) ? "Succeed" : "Failed") << endl;
    cout << "GetRandom " << obj->getRandom() << endl;

}