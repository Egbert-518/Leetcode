/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

输入：head = [1,2,3,4]
输出：[2,1,4,3]

输入：head = [1,2,3]
输出：[2,1,3]

输入：head = []
输出：[]

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;    // 去掉长度为0和为1的两种情况

        // 剩下head至少长度为2
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* front = new ListNode();  // 用于指向交换的前一个节点

        while (p != nullptr && q != nullptr) {
            ListNode* temp;  // 用于交换

            if (first_entry_) {
                first_entry_ = false;
                temp = q->next;
                q->next = p;
                p->next = temp;   // 这样交换完q在前p在后, 需要交换回来

                head = q;     // 让head指向q
                p = q;        // p指向q位置
                q = p->next;  // q指向原来p所在位置也就是q->next
                front = q;    // 保留下一次交互的前置指针front
            }
            else {
                temp = q->next;
                q->next = p;
                p->next = temp;
                front->next = q;   // 能进这front一定不是nullptr

                p = q;
                q = p->next;
                front = q;

            }

            p = p->next->next;
            if (p == nullptr)
                break;
            q = p->next;
        }

        return head;
    }

    bool first_entry_;
    Solution() : first_entry_(true){}
};


int main() {
    ListNode* third = new ListNode(3);
    ListNode* second = new ListNode(2, third);
    ListNode* head = new ListNode(1, second);
    
    Solution solution;
    head = solution.swapPairs(head);
    ListNode* p = head;
    while (p != nullptr) {
        std::cout << p->val << std::endl;
        p = p->next;
    }

    return 0;
}


/*
* 执行用时：4 ms, 在所有 C++ 提交中击败了56.05%的用户
* 内存消耗：7.24MB, 在所有 C++ 提交中击败了21.97%的用户
*/

