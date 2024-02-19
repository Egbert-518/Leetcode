/*
你可以选择使用单链表或者双链表，设计并实现自己的链表。
单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

示例:
    输入
    ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
    [[], [1], [3], [1, 2], [1], [1], [1]]
    输出
    [null, null, null, null, 2, null, 3]

    解释
    MyLinkedList myLinkedList = new MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList.get(1);              // 返回 2
    myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
    myLinkedList.get(1);              // 返回 3


 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);

0 <= index, val <= 1000
请不要使用内置的 LinkedList 库。
调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。

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
 

class MyLinkedList {
public:
    MyLinkedList() {
        dummy_head = new ListNode(0, nullptr);
    }
    
    int get(int index) {
        // head的值属于下标0, head->next为下标1, 以此类推
        ListNode* p = dummy_head->next;
        for (int i = 0; i < index; i++)
        {
            if (p == nullptr) {
                return -1;
            }
            p = p->next;
        }
        if (p == nullptr) {
            return -1;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode* add_node = new ListNode(val);
        add_node->next = dummy_head->next;
        dummy_head->next = add_node;
    }
    
    void addAtTail(int val) {
        ListNode* p = dummy_head;   // 伪头指针
        ListNode* q = p->next;      // head
        while (q != nullptr)
        {
            q = q->next;
            p = p->next;
        }
        // q为nullptr, 则p->next为q, p为末节点
        ListNode* add_node = new ListNode(val);
        p->next = add_node;
    }
    
    void addAtIndex(int index, int val) {   // 插入到下标为index之前, 如果index比链表长度更大, 则不需要将节点插入, 如果相等, 则添加到链表末尾
        ListNode* p = dummy_head;   // 伪头指针
        ListNode* q = dummy_head->next;
        int cur_idx = 0;
        
        for (; cur_idx < index; cur_idx++)
        {   
            if (q == nullptr)
                break;
            p = p->next;
            q = q->next;
        }

        // q会停在cur_idx处
        if (index > cur_idx + 1) {
            return;    // 不插入
        }
        else if (index == cur_idx + 1) {
            if (cur_idx == 0) {    // 头节点为空, 这时候长度记作0而非1
                return;
            }
            ListNode* add_node = new ListNode(val);
            p->next = add_node;
        }
        else {
            ListNode* add_node = new ListNode(val);
            add_node->next = q;
            p->next = add_node;
        }

    }
    
    void deleteAtIndex(int index) {
        ListNode* p = dummy_head;   // 伪头指针
        ListNode* q = dummy_head->next;
        int cur_idx = 0;
        
        for (; cur_idx < index; cur_idx++)
        {   
            if (q == nullptr)
                break;
            p = p->next;
            q = q->next;
        }

        if (q == nullptr) {
            return;   // 不做删除
        }
        else {
            p->next = q->next;
            delete(q);
        }
    }

private:
    ListNode* dummy_head;   // 伪头节点
};

int main()
{   
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(3, 2);
    // obj->get(0);


    return 0;
} 

/*
* 执行时间36ms, 击败90.22%c++用户
* 内存消耗19.78M, 击败6.31%c++用户
*/