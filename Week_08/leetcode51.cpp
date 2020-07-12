#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    int size;
    int mask;
    vector<vector<int>> binRes;
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n < 1) return {};
        size = n ;
        mask = (1 << n) - 1;

        vector<int> firstSol(n, 0);
        BackTrack(0, 0, 0, 0, firstSol);

        return GenRes();
    }
private:
    void BackTrack(int row, int left, int down, int right, vector<int>& curSol) {
        if (row == size) {
            binRes.push_back(curSol);
        } else {
            int bitMap = mask & ~(left | down | right);
            while (bitMap) {
                int pick = -bitMap & bitMap;
                curSol[row] = pick;
                BackTrack(row + 1, (pick | left) << 1, pick | down, (pick | right) >> 1, curSol);
                bitMap ^= pick;
            }
        }
    }

    vector<vector<string>> GenRes() {
        vector<vector<string>> res(binRes.size(), vector<string>(size, string(size, '.')));
        for (int i = 0; i < binRes.size(); ++i) {
            for (int j = 0; j < size; ++j) {
                int binIdx = binRes[i][j];
                int count = 0;
                while (binIdx) {
                    binIdx >>= 1;
                    ++count;
                }
                res[i][j][size - count] =  'Q';
            }
        }
        return res;
    }
};