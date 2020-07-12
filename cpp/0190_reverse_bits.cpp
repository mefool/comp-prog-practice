/* Leetcode - Problem 190 - Reverse Bits
   Given a set of distinct integers, nums, return all possible subsets.
  
  0190_reverse_bits.cpp
  g++ 0190_reverse_bits.cpp -o reverse_bits.exe

  References:
  >
*/

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t result = 0;
      int count = sizeof(n)*8;
      while (count--){
        result <<= 1;
        result |= n & 1;
        n >>= 1;
      }
      return result;
    }
};

int main() {
  uint32_t n = 1;

  Solution solver;
  uint32_t result = solver.reverseBits(n);

  //cout << "size   = "<< sizeof(n) << "("<< sizeof(n)*8 << ")" << endl;

  cout << "n      = " << bitset<8*sizeof(n)>(n) << endl;
  cout << "result = " << bitset<8*sizeof(result)>(result) << endl;
  
}
