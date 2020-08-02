/* Leetcode - Problem 705 - Design Hashset - https://leetcode.com/problems/design-hashset/
   Design a HashSet without using any built-in hash table libraries.

   To be specific, your design should include these functions:
     add(value): Insert a value into the HashSet. 
     contains(value) : Return whether the value exists in the HashSet or not.
     remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
   
  
  0705b_design_hashset.cpp
  g++ 0705b_design_hashset.cpp -o design_hashset.exe

  References:
  >
*/

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define RANGE 31

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> hash[RANGE]; // not really a set, but is now a hash  
    MyHashSet() {
      // in order to implement a set, a better way to quickly search if a key
      // already exists, and for that a binary tree would probably be of use.
    }
    
    void add(int key) {
        int bkt = key%RANGE;
        hash[bkt].push_back(key);
    }
    
    void remove(int key) {
        int bkt = key%RANGE;
        for (int i=0; i < hash[bkt].size(); i++)
            if (hash[bkt][i] == key){
                hash[bkt].erase(hash[bkt].begin() + i);
                i--;
            }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int bkt = key%RANGE;
        for (int i=0; i < hash[bkt].size(); i++)
            if (hash[bkt][i] == key)
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
