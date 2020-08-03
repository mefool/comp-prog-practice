/* Leetcode - Problem 125 - Valid Palindrome - https://leetcode.com/problems/valid-palindrome/
   Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  g++ 0125_valid_palindrome.cpp -o valid_palindrome .exe

  References:
  > http://www.cplusplus.com/reference/cctype/isalnum/
*/

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length();
        while (i < j) {
            //iterate to next
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            // palindrome check
            if (tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
                continue;
            }
            return false;
        }
        return true;
    }
};
