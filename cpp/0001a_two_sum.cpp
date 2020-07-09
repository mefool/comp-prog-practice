/* Leetcode - Problem 1 - Two Sum
  Given an array of integers, return indices of the two numbe that add up to a specific target.
  
  0001a_two_sum.cpp
  g++ 0001a_two_sum.cpp -o two_sum.exe
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // Brute force implementation
      // O(n^2) time complexity, O(1) space complexity
      vector <int> result;

      for (int i = 0; i < nums.size(); i++){
        for (int j = i+1; j < nums.size(); j++){
          if (nums[i] + nums[j] == target){
            result.push_back(i);
            result.push_back(j);
            return result;
          }
        }
      }
      // We assume there is *exactly* one solution
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
