#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int wordLen = 0;
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter != ' ') {
                wordLen++;
            } else {
                reverse(iter - wordLen, iter);
                wordLen = 0;
            }
        }
        reverse(s.end() - wordLen, s.end());
        return s;
    }
};