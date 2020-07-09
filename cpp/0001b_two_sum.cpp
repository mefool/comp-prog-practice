/* Leetcode - Problem 1 - Two Sum
  Given an array of integers, return indices of the two numbe that add up to a specific target.
  
  0001b_two_sum.cpp
  g++ 0001b_two_sum.cpp -o two_sum.exe

  References:
  > http://www.cplusplus.com/reference/unordered_map/unordered_map/
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // Map implementation
    // O(n) time complexity, O(n) space complexity
    vector <int> result(2);

    map<int, int> aux; // <key, value> -> <nums[i], i>
    //unordered_map<int, int> aux;
    
    for (int i = 0; i < nums.size(); i++) {
      // Finding the pair number
      if (aux.find(target-nums[i]) != aux.end()){
        result[0] = aux[target-nums[i]];
        result[1] = i;
        break;
      }
      // Adding the current value to the map
      aux[nums[i]] = i;
    }
    return result;
  }
};

int main() {
  vector<int> nums;
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);

  int target = 5;
  Solution solver;
  vector<int> result = solver.twoSum(nums, target);

  if (result.empty()){
    cout << "Not found" << endl;
    return 0;
  }
  
  cout << "Indices for the sum to be equal to " << target << ": ["
       << result[0] <<  ", " << result[1] << "]" << endl;
  
  return 0;
}
