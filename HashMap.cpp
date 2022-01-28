#include <bits/stdc++.h>
using namespace std;

class HashMap{
    private:
        static const int hashsize = 10;
        list<pair<int, int>> table[hashsize]; // array of type linked-list where list contains pair<int, int>
        /*
          _________________________________________
          | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
            ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓
               |11, 243 | -> Linked List Node => list<pair<int,int>>
               |1, 16 | 
               |21, 27 |
               |111, 12883 |
        */
        
    public:
        int hashFunction(int key);
        bool isEmpty();
        void insert(int key, int value);
        void remove(int key);
        int search(int key);
        void print();
};

// Function to check if the hashmap is empty
bool HashMap::isEmpty(){ 
    int sum = 0;
    for(int i = 0; i < hashsize; i++){
        sum += table[i].size();
    }
    
    return sum == 0;
}

int HashMap::hashFunction(int key){
    return key%hashsize;
}

// function to insert a key value pair in hashmap
void HashMap::insert(int key, int value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    bool keyExists = false;
    
    for(auto itr = begin(cell); itr != end(cell); itr++){
        if(itr->first == key){       
            keyExists = true;
            itr->second = value;
            break;
        }
    }
    
    if(!keyExists){
        cell.emplace_back(key, value);
    }
    return;
}

// function to remove a key value pair in hashmap
void HashMap::remove(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    bool keyExists = false;
    
    for(auto itr = begin(cell); itr != end(cell); itr++){
        if(itr->first == key){
            keyExists = true;
            itr = cell.erase(itr);
            break;
        }
    }
    return;
}

// function to print all the key value pairs present in the HashMap
void HashMap::print(){
    for(int i = 0; i < hashsize; i++){
        if(table[i].size() == 0) continue;
        
        for(auto itr = table[i].begin(); itr != table[i].end(); itr++){
            cout<<"Key: "<<itr->first<<" Value: "<<itr->second<<endl;
        }
    }
    return;
}
