#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // grid(i, j) = grid(i, j) + min(grid(i+1, j), grid(i, j + 1))
        int len = grid.size();
        int len2 = grid[0].size();
        for (int i = len - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                if (i == len - 1 && j != len2 - 1) {
                    grid[i][j] = grid[i][j] + grid[i][j + 1];
                } else if (j == len2 - 1 && i != len - 1) {
                    grid[i][j] = grid[i][j] + grid[i + 1][j];
                } else if (i != len - 1 && j != len2 - 1) {
                    grid[i][j] = grid[i][j] + min(grid[i][j + 1], grid[i + 1][j]);
                }
            }
        }
        
        return grid[0][0];
    }
};