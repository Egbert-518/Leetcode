#include <iostream>
#include <vector>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;  // 进位值
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(l1 != nullptr && l2 != nullptr) {
            int temp_sum = l1->val + l2->val + carry;
            if (temp_sum < 10)
            {
                carry = 0;
            }
            else
            {
                carry = 1;
                temp_sum -= 10;
            }
            ListNode* temp_node = new ListNode(temp_sum);
            if (head == nullptr)
            {
                head = temp_node;
                tail = temp_node;
            }
            else
            {
                tail->next = temp_node;
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        // 有一个数字结束了
        if (l1 == nullptr)
        {
            while (l2 != nullptr)
            {
                int temp_sum = carry + l2->val;
                if (temp_sum < 10)
                {
                    carry = 0;
                }
                else
                {
                    carry = 1;
                    temp_sum -= 10;
                }
                ListNode* temp_node = new ListNode(temp_sum);
                tail->next = temp_node;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        else if (l2 == nullptr)
        {
            while (l1 != nullptr)
            {
                int temp_sum = carry + l1->val;
                if (temp_sum < 10)
                {
                    carry = 0;
                }
                else
                {
                    carry = 1;
                    temp_sum -= 10;
                }
                ListNode* temp_node = new ListNode(temp_sum);
                tail->next = temp_node;
                tail = tail->next;
                l1 = l1->next;
            }
        }
        // n位+n位可能为n+1位
        if (carry == 1)
        {
            ListNode* temp_node = new ListNode(carry);
            tail->next = temp_node;
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    }
};

