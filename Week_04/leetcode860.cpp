#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (auto i : bills) {
            if (i == 5) {
                five++;
            } else if (i == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else if (i == 20) {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};