/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

示例1:
    输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
    输出：Intersected at '8'
    解释: 相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
         从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
         在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

listA 中节点数目为 m
listB 中节点数目为 n
0 <= m, n <= 3 * 10^4
1 <= Node.val <= 10^5
0 <= skipA <= m
0 <= skipB <= n
如果 listA 和 listB 没有交点，intersectVal 为 0
如果 listA 和 listB 有交点，intersectVal == listA[skipA + 1] == listB[skipB + 1]

题目数据 保证 整个链式结构中不存在环。
注意，函数返回结果后，链表必须 保持其原始结构

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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*因为不能破坏链表原始结构, 因此不能先将其倒序, 再从末尾开始同步遍历*/
        /*那么就先求出A、B的长度, 确定短的那个, 让长的那个移动到短的size处*/

        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        // 让A是长的那个链表, 方便代码
        curA = headA;
        curB = headB;
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        
        for (int i = 0; i < lenA - lenB; i++)
        {
            curA = curA->next;   // 让curA与curB末几位对齐
        }

        for (int i = 0; i < lenB; i++)
        {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};


int main()
{   

    return 0;
} 

/*
* 执行时间36ms, 击败84.13%c++用户
* 内存消耗14.49M, 击败96.39%c++用户
*/

/*
* 有一种奇特的思路, 就是headA与headB一直指向下一位(用一个新指针指p, q), 当p为nullptr时令p = headB, 同样当q为nullptr时使其指向headA
* 这样遍历两次, 它们走过的长度必然是相等的, 只要判断一直判断p==q?即可. 最多走向末尾两次
*/