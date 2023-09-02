/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列

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
* 执行用时：4 ms, 在所有 C++ 提交中击败了92.33%的用户
* 内存消耗：14.07MB, 在所有 C++ 提交中击败了66.28%的用户
*/
