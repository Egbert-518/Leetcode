/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例1:
    输入：head = [1,2,3,4]
    输出：[2,1,4,3]

示例1:
    输入：head = [1,2,3]
    输出：[2,1,3]

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

*/

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;   // 排除长度为0和1两种情况
        }

        ListNode* t = new ListNode(0, head);
        ListNode* p = head;
        ListNode* q = head->next;
        bool first_swap = true;

        while (true) 
        {   
            p->next = q->next;
            q->next = p;
            t->next = q;
            if (first_swap) {
                first_swap = false;
                head = t->next;
            }

            if (p->next == nullptr || p->next->next == nullptr) {   // 先判断q->next, 若为true, 则不会执行||后面的, 避免了nullptr->next报错
                break;
            }

            t = p;
            q = p->next->next;
            p = p->next;

            
        }

        return head;
    }
};


int main()
{   

    return 0;
} 

/*
* 执行时间4ms, 击败48.81%c++用户
* 内存消耗7.91M, 击败6.20%c++用户
*/