/* Leetcode - Problem 520 - Detect Captital - https://leetcode.com/problems/detect-capital/
   Given a word, you need to judge whether the usage of capitals in it is right or not.
   
  
  0520_detect_capital.cpp
  g++ 0520_detect_capital.cpp -o detect_capital.exe

  References:
  >
*/

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    if (word.size() < 2)
      return true;
        
    if (isupper(word[0])){
      // ALL
      if (isupper(word[1])){
        for (int i = 1; i < word.size(); i++)
          if (islower(word[i]))
            return false;
        return true;
      }
      // All
      if (islower(word[1])){
        for (int i = 1; i < word.size(); i++)
          if (isupper(word[i]))
            return false;
        return true;
      }
    } else {
      // all
      for (int i = 1; i < word.size(); i++)
        if (isupper(word[i]))
          return false;
      return true;
            
    }
    return false; // ? 
  }
};
