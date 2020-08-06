/* Leetcode - Problem 442 - Find All Duplicates in an Array
   Given an array of integers, 1 <= a[i] <= n (n = size of array), some elements appear twice and others appear once.

   Find all the elements that appear twice in this array.

   Could you do it without extra space and in O(n) runtime?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        
        // go throught the vector
        for (int i=0; i<nums.size(); i++) {
            // obtain the corresponding index
            int idx = abs(nums[i]) - 1;
            // check for colision
            // if some other number already referenced this index
            if (nums[idx] < 0)
                ret.push_back(idx+1);
            // mark this number as already seen
            nums[idx] = -nums[idx];
        }
        return ret;
    }
};
