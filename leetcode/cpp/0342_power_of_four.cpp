/* Leetcode - Problem 342 - Power of four
   g++ 0342_power_of_four.cpp -o power_of_four.exe
   
   Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
   
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // (num > 0) ---------- the following bitwise operations might be true
        //                      for a negative number that isn't a power of 4
        // (num & 0x55555555) - 4 is 0100 or 0x0...04, 16 is 00010000 or
        //                      0x0...10 by checking the (0101).rep or 0x5..5
        //                      we are checking this pattern (briefly explained,
        //                      improve later)
        // (num & num-1) ------ this bitwise operation checks if there is only
        //                      one bit with 1 (making it a power of 2)
        return (num > 0) && (num & 0x55555555) && (num & num-1) == 0;
    }
};
