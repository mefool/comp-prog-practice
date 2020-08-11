/* Leetcode - Problem 274 - H Index - https://leetcode.com/problems/h-index/
   Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n+1);
        for (const auto& c:citations) {
            if (c >= n)
                bucket[n]++;
            else
                bucket[c]++;
        }
        int cnt = 0;
        for (int i = n; i >=0; i--) {
            cnt += bucket[i];
            if (cnt >= i)
                return i;
        }
        return 0;
    }
};
