#include "istream"
#include "vector"
#include "map"
#include "queue"
using namespace std;

class Solution {
public:
    struct cmpByValue {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> map; // <元素， 频率>
        for (int i = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
        }
        // 建立前k大的小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmpByValue> heap;
        int count = 0;
        auto iter = map.begin();
        for (; iter != map.end(); ++iter) {
            if (count == k) {
                break;
            }
            heap.push(*iter);
            ++count;
        }
        // 更新小根堆
        for (; iter != map.end(); ++iter) {
            if (iter->second > heap.top().second) {
                heap.pop();
                heap.push(*iter);
            }
        }
        
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res.at(i) = heap.top().first;
            heap.pop();
        }

        return res;
    }
};