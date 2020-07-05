#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> pre;
    int find(vector<int>& vec, int n) {
        if (vec[n] == -1) return n;
        return find(vec, vec[n]);
    }

    void Union(vector<int>& vec, int m, int n) {
        int p_m = find(vec, m);
        int p_n = find(vec, n);
        if (p_m != p_n) {
            vec[p_m] = p_n;
        }
    }
  
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<int> parent(N, -1);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (M[i][j] == 1 && i != j) {
                    Union(parent, i, j);
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            if (parent[i] == -1) {
                ret++;
            }
        }
        return ret;
    }
    
};