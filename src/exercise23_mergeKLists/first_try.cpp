/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        // 考虑利用之前写的两个链表合并, 进行两两合并
        ListNode* mergeList = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            mergeList = this->mergeTwoLists(mergeList, lists[i]);
        }

        return mergeList;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if (list1 == nullptr && list2 != nullptr)
            return list2;
        else if (list1 != nullptr && list2 == nullptr)
            return list1;
        else {
            // 去掉一些好判断的情况
            ListNode* p1 = list1;
            ListNode* p2 = list2;

            ListNode* merge_head;   // 第一步指向只是为了去除nullptr不能使用next的问题
            if (p1->val < p2->val) {
                merge_head = list1;
                p1 = p1->next;
            }
            else {
                merge_head = list2;
                p2 = p2->next;
            }

            ListNode* merge_ptr = merge_head;

            while (p1 != nullptr && p2 != nullptr) {
                if (p1->val < p2->val) {
                    merge_ptr->next = p1;   // 让合成列表的next指向当前小的那部分
                    while (p1->next != nullptr && p1->next->val < p2->val)  // 让小的指针往下走, 直到大于另一个列表, 或到空; 若非空, p1会停在大于p2的前一个, 也即p1->next才是大于p2
                        p1 = p1->next;
                    // 此时merge还指在这一段顺序的头, 到现在应该指向p1了, 并且让p1再次指向它的next
                    merge_ptr = p1;
                    p1 = p1->next;
                }
                else {
                    merge_ptr->next = p2;
                    while (p2->next != nullptr && p2->next->val <= p1->val)
                        p2 = p2->next;
                    merge_ptr = p2;
                    p2 = p2->next;
                }
            }

            if (p1 != nullptr)  // 有没拼完的, 拼完
                merge_ptr->next = p1;
            else if (p2 != nullptr)
                merge_ptr->next = p2;

            // 再者就是两者都为空
            return merge_head;
        }
    }
};


int main() {


    return 0;
}


/*
* 执行用时：132 ms, 在所有 C++ 提交中击败了26.02%的用户
* 内存消耗：12.33MB, 在所有 C++ 提交中击败了93.52%的用户
*/

