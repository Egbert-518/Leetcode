/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例1:
    输入：head = [1,2,3,4]
    输出：[2,1,4,3]

示例 2：
    输入：head = []
    输出：[]

示例 3：
    输入：head = [1]
    输出：[1]

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);
        if (dummy_head->next == nullptr || dummy_head->next->next == nullptr) {
            // 如果下两位至少有一个不存在
            return dummy_head->next;   // 直接返回头节点, 不需要调换顺序
        }

        ListNode* pre = dummy_head;
        ListNode* p = dummy_head->next;
        ListNode* q = dummy_head->next->next;
        while (true)
        {
            // 交换节点
            pre->next = q;
            p->next = q->next;
            q->next = p;

            // 更新指针
            pre = p;   // pre指针指向交换后的p, 交换后顺序是pre->q->p->new
            if (pre->next == nullptr || pre->next->next == nullptr) {
                return dummy_head->next;
            }
            p = pre->next;
            q = pre->next->next;
        }
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间2ms, 击败50.25% c++用户
* 消耗内存9.28M, 击败19.77% c++用户
*/
