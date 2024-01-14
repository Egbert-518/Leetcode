/*
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

示例1:
    输入：head = [3,2,0,-4], pos = 1
    输出：返回索引为 1 的链表节点
    解释：链表中有一个环，其尾部连接到第二个节点。

链表中节点的数目范围在范围 [0, 10^4] 内
-10^5 <= Node.val <= 10^5
pos 的值为 -1 或者链表中的一个有效索引
*/

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        /*思想是利用快慢指针, 快指针每次移动2个节点, 慢指针每次移动一个节点, 若存在环, 则快慢指针一定会相遇*/
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while (true)
        {
            if (fast == nullptr) {
                // 说明快指针到头了, 快慢指针没有相遇, 故没有环
                return nullptr;
            }
            fast = fast->next;
            if (fast == nullptr) {
                // 说明快指针到头了, 快慢指针没有相遇, 故没有环, 每次快指针next时, 都需要查询一下, 防止
                return nullptr;
            }
            else {
                fast = fast->next;
                slow = slow->next;
                if (slow == fast) {
                    // slow与fast指针相遇, 说明有环, 这个相等不仅仅是值相等, 也需要地址相等
                    break;
                }
            }
        }

        ListNode* p = head;
        while (true)
        {
            if (slow == p) {
                return p;
            }
            else {
                p = p->next;
                slow = slow->next;
            }
        }
    }
};

int main() 
{

    return 0;
}

/*
* 运行时间16ms, 击败12.02％ c++用户
* 消耗内存8.02M, 击败24.91% c++用户
*/
