/* Leetcode - Problem 119 - Pascal Triangle II
   Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
   https://leetcode.com/problems/pascals-triangle-ii/
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int i = 0; i <= rowIndex; i++) {
            row.push_back(1);
            for (int j = i - 1; j >= 1; --j) 
                row[j] = row[j] + row[j-1];
        }
        return row;
    }
};
