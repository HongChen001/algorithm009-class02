#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        int left = 0, right = n - 1;
        int res = 0;
        int maxleft = 0, maxright = 0;
        while (left <= right) {
            if (A[left] <= A[right]) {
                if (A[left] >= maxleft) {
                    maxleft = A[left];
                } else {
                    res += maxleft - A[left];
                }
                left++;
            } else {
                if (A[right] >= maxright) {
                    maxright = A[right];
                } else {
                    res += maxright - A[right];
                }
                right--;
            }
        }
        return res;
    }

    int trap(vector<int>& height, int type) {
        // type == 1 双指针 type == 2 暴力求解 type == 3 栈的应用
        // 双指针法思路：最优解
        // 1.left、right指针
        // 2.while left < right do:
        //      if height[left] < height[right]
        //          if height[left] >= left_max, 更新left_max
        //          else 累加left_max - height[left] 到 result
        //          left = left + 1
        //      else 
        //          if height[right] >= right_max, 更新right_max
        //          else 累加 right_max - hight[right] 到 result
        //          right = right - 1

        int res = 0;
        if (type == 1) {
            int left = 0, right = height.size() - 1;
            int left_max = 0, right_max = 0;
            while (left <= right)
            {
                if (height[left] <= height[right]) {
                    if (height[left] >= left_max) {
                        left_max = height[left];
                    } else {
                        res += (left_max - height[left]);
                    }
                    left++;
                } else {
                    if (height[right] >= right_max)
                    {
                        right_max = height[right];
                    } else {
                        res += (right_max - height[right]);
                    }
                    right--;
                }
            }
        } else if (type == 2) {
            int size = height.size();
            for (int i = 0; i < size - 1; i++)
            {
                int max_left = 0, max_right = 0;
                for (int j = i; j >= 0; j--) {
                    max_left = max(max_left, height[j]);
                }
                for (int j = i; j < size; j++) {
                    max_right = max(max_right, height[j]);
                }
                res += min(max_left, max_right) - height[i];
            }
        } else if (type == 3) {
            int cur = 0;
            stack<int> st;
            while (cur < height.size()) {
                while (!st.empty() && height[cur] > height[st.top()]) {
                    int top = st.top();
                    st.pop();
                    if (st.empty()) {
                        break;
                    }
                    int dis = cur - st.top() - 1;
                    int b_height = min(height[cur], height[st.top()]) - height[top];
                    res += dis * b_height;
                }
                st.push(cur++);
            }
        }

        return res;
    }
};

int main() {
    Solution test = Solution();
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = test.trap(arr, 12);
    cout << result << endl;

    vector<int> data;
    for (int i = 0; i < 12; i++)
    {
        data.push_back(arr[i]);
    }
    
    result = test.trap(data, 1);
    cout << result << endl;
    result = test.trap(data, 2);
    cout << result << endl;
    result = test.trap(data, 3);
    cout << result << endl;
    getchar();
    return 0;
}