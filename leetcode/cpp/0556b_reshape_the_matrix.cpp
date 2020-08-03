/* Leetcode - Problem 3 - Reshape the Matrix - https://leetcode.com/problems/reshape-the-matrix/
   In MATLAB, there is a very useful function called 'reshape', which can 
   reshape a matrix into a new one with different size but keep its 
   original data.

   You're given a matrix represented by a two-dimensional array, and two 
   positive integers r and c representing the row number and column number 
   of the wanted reshaped matrix, respectively.

   g++ 0566b_reshape_the_matrix.cpp -o reshape_matrix.exe

   References:
   > https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix

   Comments:
   > Compared to the (a) version of this problem the runtime is identical and it uses
   more memory. 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c || r < 1 || c < 1) {
            return nums;
        }

        vector<vector<int>> res(r, vector<int>(c, 0));
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[(i*n + j) / c][(i*n + j) % c] = nums[i][j];

        return res;
        
    }
};
