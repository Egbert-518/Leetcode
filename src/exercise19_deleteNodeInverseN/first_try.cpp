/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_size = 0;
        // 获取整个list的长度
        for (ListNode* p = head; p != nullptr;) {
            list_size++;
            p = p->next;
        }

        ListNode* front = head;
        for (int i = 0; i < list_size - n - 1; i++) {  // 使front指向要被删除的前一个Node
            front = front->next;  
        }
           
        ListNode* need_delete;
        if (list_size - n - 1 >= 0) {
            need_delete = front->next;  // 我们规定back是要删除的Node
        }
        else {
            if (list_size == 1) {
                return nullptr;
            }
            else {
                return head->next;
            }   
        }

        front->next = need_delete->next;
        delete need_delete;
        return head;
    }
};

int main() {

    return 0;
}


/*
* 执行用时：12 ms, 在所有 C++ 提交中击败了28.62%的用户
* 内存消耗：10.27MB, 在所有 C++ 提交中击败了15.92%的用户
*/
