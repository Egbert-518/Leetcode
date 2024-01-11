/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]


链表中的节点数目为 n
1 <= k <= n <= 5000
0 <= Node.val <= 1000

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
    ListNode* reverseKGroup(ListNode* head, int k) {  // 注意k一定是不超过n的
        ListNode* p = head;
        int size_n = 0;

        // 获取链表的长度
        while (p != nullptr) {
            size_n = size_n + 1;
            p = p->next;
        }

        int group = size_n / k;   // 获取能翻转几组的值
        ListNode** extra_ptr = new ListNode* [k];   // 进阶版, 额外O(1)内存, 用这k个指针指向每一个要用的节点
        ListNode* next_front = new ListNode;   // 下一次要指向的第一个指针
        ListNode* last_back = new ListNode;    // 上一次计算的最后一个指针

        for (int ii = 0; ii < group; ii++) {
            if (ii == 0) {
                // 第一次处理, 与head有关
                extra_ptr[0] = head;
                for (int jj = 1; jj < k; jj++) {
                    extra_ptr[jj] = extra_ptr[jj - 1]->next;   // 让每一个指针指向前一个的next, 完毕后k个指针按顺序分别对应k个要交换的节点
                }
                next_front = extra_ptr[k - 1]->next;  // 指向下一次要用的"head"节点
                for (int jj = k - 1; jj > 0; jj--) {
                    extra_ptr[jj]->next = extra_ptr[jj - 1];
                }
                extra_ptr[0]->next = next_front;
                head = extra_ptr[k - 1];
                last_back = extra_ptr[0];  // 因为已经交换, 所以last_back应该指向extra_ptr[0]

            }
            else {
                // 后面的处理与front有关
                extra_ptr[0] = next_front;
                for (int jj = 1; jj < k; jj++) {
                    extra_ptr[jj] = extra_ptr[jj - 1]->next;   // 让每一个指针指向前一个的next, 完毕后k个指针按顺序分别对应k个要交换的节点
                }
                next_front = extra_ptr[k - 1]->next;  // 虽然报警, 但必不可能是null指针的next, 因为一开始已经判断过size
                for (int jj = k - 1; jj > 0; jj--) {
                    extra_ptr[jj]->next = extra_ptr[jj - 1];
                }
                extra_ptr[0]->next = next_front;
                last_back->next = extra_ptr[k - 1];
                last_back = extra_ptr[0];  // 因为已经交换, 所以last_back应该指向extra_ptr[0]
            }
        }

        return head;
    }

};


int main() {
    Solution solution;

    ListNode* fifth = new ListNode(5);
    ListNode* forth = new ListNode(4, fifth);
    ListNode* third = new ListNode(3, forth);
    ListNode* second = new ListNode(2, third);
    ListNode* head = new ListNode(1, second);

    head = solution.reverseKGroup(head, 3);

    ListNode* p = head;
    while (p != nullptr) {
        std::cout << p->val << std::endl;
        p = p->next;
    }

    return 0;
}


/*
* 执行用时：20 ms, 在所有 C++ 提交中击败了18.90%的用户
* 内存消耗：11.18MB, 在所有 C++ 提交中击败了6.52%的用户
*/

