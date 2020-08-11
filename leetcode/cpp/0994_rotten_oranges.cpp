/* Leetcode - Problem 994 - Rotting Oranges
   https://leetcode.com/problems/rotting-oranges/
*/

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return -1;
        // counters
        int min_cnt = 0, fresh_cnt = 0;
        // auxiliary variables
        int x_size = grid.size();
        int y_size = grid[0].size();

        // queue structure for storing the coordinates of the rotten oranges
        queue<pair<int, int>> rotten_q;

        // counting of the fresh oranges and search for the rotten oranges
        for (int i=0; i < x_size; i++) {
            for (int j=0; j < y_size; j++) {
                if (grid[i][j] == 1) 
                    fresh_cnt++;
                else
                if (grid[i][j] == 2)
                    rotten_q.push({i,j});
            }   
        }
        // directing of rotten spread in one minute, (dx,dy) = (dir[i], dir[i+1])
        vector<int> dir = {1,0,-1,0,1};

        while (!rotten_q.empty()) {
            bool rotten_flag = false; // if rott was spread in that minute
            int curr_min_size = rotten_q.size(); // number of oranges (on the queue) that spread rott in that minute
            for (int i = 0; i < curr_min_size; i++) {
                // pair of corrdinates do the rooten orange
                auto coord = rotten_q.front();
                rotten_q.pop(); // removing from queue the rotten orange

                for (int d = 0; d < 4; d++) { // search for fresh oranges in the direction of spread of the rotten oranges
                    int x = coord.first + dir[d];
                    int y = coord.second + dir[d+1];
                    if (x>=0 && x < x_size && y>=0 && y < y_size && grid[x][y] == 1) {
                        grid[x][y] = 2; // fresh to rotten
                        rotten_q.push({x, y}); // add to rotten queue
                        fresh_cnt--;
                        rotten_flag = true;
                    }
                } 
            }
            if (rotten_flag)
                min_cnt++;
            //else //if (!rotten_flag) should mean rotten_q is now empty
                //break;
        }
        return (fresh_cnt == 0) ? min_cnt : -1;
    }
};
