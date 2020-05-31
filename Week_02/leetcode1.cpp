#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 一遍哈希表
        map<int, int> map;
        vector<int> res;
        int lenth = nums.size();
        for (int i = 0; i < lenth; ++i) {
            int complement = target - nums[i];
            auto iter = map.find(complement);
            if (iter != map.end()) {
                res.push_back(iter->second);
                res.push_back(i);
                return res;
            }
            map.insert(make_pair(nums[i], i));
        }
        
        // 暴力求解
        for (int i = 0; i < lenth; ++i) {
            for (int j = i + 1; j < lenth; ++j) {
                if (nums[i] == target - nums[j]) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

        return res;
    }
};
