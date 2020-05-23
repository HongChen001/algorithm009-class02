#include "iostream"
#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2, int type) {
        // type == 1 递归法 时间复杂度O(n + m)、空间复杂度O(m + n)  n、m为链表l1、l2长度
        // type == 2 迭代法 时间复杂度O(n + m)、空间复杂度O(1)
        if (type == 1) {
            if (l1 == nullptr) {
                return l2;
            } else if (l2 == nullptr) {
                return l1;
            } else if (l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2, type);
                return l1;
            } else {
                l2->next = mergeTwoLists(l1, l2->next, type);
                return l2;
            }
        } else if (type == 2) {
            ListNode* head = new ListNode(-1);
            ListNode* prev = head;
            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    prev->next = l1;
                    l1 = l1->next;
                } else {
                    prev->next = l2;
                    l2 = l2->next;
                }
                prev = prev->next;
            }
            prev->next = (l1 == nullptr) ? l2 : l1;
            return head->next;
        }

        return nullptr;
    }
};
