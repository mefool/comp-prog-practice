/* Leetcode - Problem 78 - Add two numbers
   Given a set of distinct integers, nums, return all possible subsets.
  
  0078_subsets.cpp
  g++ 0078_subsets.cpp -o subsets.exe

  References:
  >
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    int start;
    for (int i = 0; i < nums.size(); i++){
      start = 0;
      for (int end = result.size(); start < end; start++){
        vector<int> aux = result[start];
        aux.push_back(nums[i]);
        result.push_back(aux);
      }
    }
    return result;
  }
};

int main() {
  vector<int> big_set{1,2,3};

  cout << "big_set: [";
  for (int x : big_set)
    cout << x << ", ";
  cout << "]"<< endl;

  
  Solution solver;
  vector<vector<int>> result = solver.subsets(big_set);

  cout << "subsets: \n[\n";
  for (vector<int> x : result){
    cout << "\t[";
    for (int y : x)
      cout << y << ", ";
    cout << "]," << endl;
  }
  cout << "]" << endl;
}
