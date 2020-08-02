/* Leetcode - Problem 3 - Longest Substring Without Repeating Characters - https://leetcode.com/problems/longest-substring-without-repeating-characters/
   Given a string, find the length of the longest substring without repeating characters.

  g++ 0003_too_long.cpp -o too_long.exe

  References:
  >
*/

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //int table['z' -'a'] = {0};
        int table[128] = {0};
        int length = 0;
        
        int curr = 0;
        for (int i = 0; i < s.size(); i++){
            curr = max(table[s[i]], curr);
            length = max(length, i-curr+1);
            table[s[i]] = i+1;
        }
        return length;
    }
};
