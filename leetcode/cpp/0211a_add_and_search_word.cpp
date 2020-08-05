/* Leetcode - Problem 211 - Add and Search Word - Data structure design
  Design a data structure that supports the following two operations:
  {addWord(word); bool search(word)}
  search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
  
  References:
  >
*/

#include <iostream>
#include <set>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words[word.size()].push_back(word); //push to the vector associated with the size hash
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for (const auto& s:words[word.length()]) 
            if (isEqual(s,word)) 
                return true;
        return false;
    }
private:
    unordered_map <int, vector<string>>words;
    
    bool isEqual(string a, string b){
        for(int i = 0; i < a.length(); i++){
            if (b[i] == '.' || b[i] == a[i]) continue;
            return false;
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
