/* Leetcode - 705 - Design Hashset - https://leetcode.com/problems/design-hashset/
   Design a HashSet without using any built-in hash table libraries.

   To be specific, your design should include these functions:
     add(value): Insert a value into the HashSet. 
     contains(value) : Return whether the value exists in the HashSet or not.
     remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
   
  
  0705a_design_hashset.cpp
  g++ 0705a_design_hashset.cpp -o design_hashset.exe

  References:
  >
*/

#include <iostream>
#include <bitset>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> hash; // not hash, not proud 
    MyHashSet() {
        // one implementation would be a 
        //   vector<vector<int>> or vector<int>[hash_range]
        // where we operate on the [key % range] vector;   
    }
    
    void add(int key) {
        hash.push_back(key);
    }
    
    void remove(int key) {
        for (int i=0; i < hash.size(); i++)
            if (hash[i] == key){
                hash.erase(hash.begin() + i);
                i--;
                //break;
            }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for (int i=0; i < hash.size(); i++)
            if (hash[i] == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
