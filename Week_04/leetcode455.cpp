#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());  

        for (int i = 0; i < g.size(); ++i) {
            for (; j < s.size(); ++j) {
                if (s[j] >= g[i]) {
                    res++;
                    j++;
                    break;
                }
            }
        }

        return res;
    }
};