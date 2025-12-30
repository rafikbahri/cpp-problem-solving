#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>

using namespace std;

class LRUCache {
private:
    // hashmap key, <value, usage/age aka rank>
    map<int, pair<int, int>> cache;
    int rank;
    int capacity;

public:
    LRUCache(int capacity) {
        this->rank = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        const auto& elt = cache.find(key);
        if(elt != cache.end()){
            // found key, inc rank
            rank++;
            elt->second.second = rank;
            // update rank of that value if it exists in another key(s)
            int value = elt->second.first;
            return value;
        }
        // didn't found elt
        cout<<"rank :: "<<rank<<"\n";
        return -1;
    }

    int findMinRankKey(){
        int minRank = INT_MAX;
        int minRankKey = -1;
        for(const auto& line : cache){
            if(line.second.second < minRank){
                minRank = line.second.second;
                minRankKey = line.first;
            }
        }
        return minRankKey;
    }
    
    void updateRanks(int value, int newRank){
        for(auto& line : cache){
            if(line.second.first == value)
                line.second.second = newRank;
        }
    }

    void put(int key, int value) {
        // in all cases, we increment the rank
        rank++;
        // if no more place for a new 
        // cout<<"val :: "<<value<<" - capacity :: "<<capacity<<"\n";
        if(capacity == 0){
            // if key exists, update its value and rank
            const auto& elt = cache.find(key);
            if(elt != cache.end()){
                elt->second = pair<int,int>{value, rank};
                return;
            }
            // key doesn't exist;
            // create key
            cache[key] = pair<int,int>{value, rank};
            // update all keys that has value in them with the new rank
            // updateRanks(value, rank - 1);
            // evict the Least Recently Used aka the elt with the smallest rank
            int minRankKey = findMinRankKey();
            cache.erase(minRankKey);
            // cout<<"erase :: key "<<minRankKey<<" - result :: "<<cache.erase(minRankKey)<<"\n";
            return;
        }
        // and there's still place in the map
        cache[key] = pair<int,int>{value, rank};
        capacity--;
    }

    void showProps(){
        cout<<"Capacity :: "<<capacity<<"\n";
        cout<<"Rank :: "<<rank<<"\n";
    }

    void show(){
        cout<<"LRU Cache"<<"\n";
        for(const auto& line : cache)
            cout<<"key :: "<<line.first<<" - val :: "<<line.second.first<<" - rank :: "<<line.second.second<<"\n";
    }
};


// int main() {
//     int capacity1 = 2;
//     LRUCache* obj = new LRUCache(capacity1);
    
//     obj->put(1, 1);
//     obj->put(2, 2);
//     cout<<obj->get(1)<<"\n";

//     // obj->show();

//     obj->put(3, 3);

//     // obj->show();

//     cout<<obj->get(2)<<"\n";
//     // obj->show();

//     obj->put(4, 4);
//     cout<<obj->get(1)<<"\n";
//     cout<<obj->get(3)<<"\n";
//     cout<<obj->get(4)<<"\n";

//     // obj->showProps();
//     // obj->show();
    
//     return 0;
// }

int main() {
    int capacity1 = 10;
    LRUCache* obj = new LRUCache(capacity1);
    
    cout<<"put 10,13"<<"\n";
    obj->put(10,13);
    cout<<"put 3,17"<<"\n";
    obj->put(3,17);
    cout<<"put 6,11"<<"\n";
    obj->put(6,11);
    cout<<"put 10,5"<<"\n";
    obj->put(10,5);
    cout<<"put 9,10"<<"\n";
    obj->put(9,10);
    cout<<"get 13"<<"\n";
    cout<<obj->get(13)<<"\n";
    cout<<"put 2,19"<<"\n";
    obj->put(2,19);
    cout<<"get 2"<<"\n";
    cout<<obj->get(2)<<"\n";
    cout<<"get 3"<<"\n";
    cout<<obj->get(3)<<"\n";
    cout<<"put 5,25"<<"\n";
    obj->put(5,25);
    cout<<"================"<<"\n";
    obj->show();
    cout<<"get 8"<<"\n";
    cout<<obj->get(8)<<"\n";
    cout<<"put 9,22"<<"\n";
    obj->put(9,22);
    cout<<"put 5,5"<<"\n";
    obj->put(5,5);
    cout<<"put 1,30"<<"\n";
    obj->put(1,30); // here
    cout<<"================"<<"\n";
    obj->show();
    cout<<"get 11"<<"\n";
    cout<<obj->get(11)<<"\n";
    cout<<"put 9,12"<<"\n";
    obj->put(9,12);
    cout<<"================"<<"\n";
    obj->show();
    cout<<"get 7"<<"\n";
    cout<<obj->get(7)<<"\n";
    cout<<"get 5"<<"\n";
    cout<<obj->get(5)<<"\n";
    cout<<"================"<<"\n";
    obj->show();
    cout<<"get 8"<<"\n";
    cout<<obj->get(8)<<"\n";
    cout<<"================"<<"\n";
    obj->show();
    cout<<"get 9"<<"\n";
    cout<<obj->get(9)<<"\n";
    cout<<"put 4,30"<<"\n";
    obj->put(4,30); // here 30
    cout<<"put 9,3"<<"\n";
    obj->put(9,3);
    cout<<"================"<<"\n";
    obj->show();
    cout<<"get 9"<<"\n";
    cout<<obj->get(9)<<"\n";
    cout<<"get 10"<<"\n";
    cout<<obj->get(10)<<"\n";
    cout<<"get 10"<<"\n";
    cout<<obj->get(10)<<"\n";
    cout<<"put 6,14"<<"\n";
    obj->put(6,14);
    cout<<"put 3,1"<<"\n";
    obj->put(3,1);
    cout<<"get 3"<<"\n";
    cout<<obj->get(3)<<"\n";
    cout<<"put 10,11"<<"\n";
    obj->put(10,11);
    cout<<"get 8"<<"\n";
    cout<<obj->get(8)<<"\n";
    cout<<"================"<<"\n";
    obj->show();
    cout<<"put 2,14"<<"\n";
    obj->put(2,14);
    cout<<"get 1"<<"\n";
    cout<<obj->get(1)<<"\n";
    cout<<"================"<<"\n";
    obj->show();
    cout<<"get 5"<<"\n";
    cout<<obj->get(5)<<"\n";    
    return 0;
}