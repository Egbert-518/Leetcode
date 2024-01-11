/*
链表的定义 单链表
    struct ListNode {
        int val;  // 节点上存储的元素
        ListNode *next;  // 指向下一个节点的指针
        ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
    };
    不定义构造函数行不行, 答案是可以的, C++默认生成一个构造函数
    如果不定义构造函数使用默认构造函数的话，在初始化的时候就不能直接给变量赋值

给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) 
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;    // 用free会报错, free与malloc匹配, new与delete匹配
        }

        if (head == nullptr) {
            // 链表长度为0
            return head;
        }

        if (head->next == nullptr) {
            // 链表长度为1
            if (head->val == val) {
                return head->next;
            }
            else {
                return head;
            }
        }

        // 至此, 链表长度至少为2
        ListNode* p = head;
        ListNode* q = head->next;

        while (q != nullptr) 
        {

            if (q->val == val) {
                q = q->next;
                free(p->next);
                p->next = q;
            }
            else {
                q = q->next;
                p = p->next;
            }
        }
        
        return head;
    }
};

int main()
{   


    return 0;
} 

/*
* 执行时间12ms, 击败97.64%c++用户
* 内存消耗15.02M, 击败72.05%c++用户
*/

/*
可以设置一个虚拟头节点, 方便操作

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

*/