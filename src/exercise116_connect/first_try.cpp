/*
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
    struct Node {
      int val;
      Node *left;
      Node *right;
      Node *next;
    }
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

示例1:
    输入：root = [1,2,3,4,5,6,7]
    输出：[1,#,2,3,#,4,5,6,7,#]
    解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。

示例 2：
    输入：root = []
    输出：[]


树中节点的数量在 [0, 2^12 - 1] 范围内
-1000 <= node.val <= 1000
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


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        /*层序遍历会好一些吧*/
        if (root == nullptr) {
            return root;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty())
        {
            int cur_size = que.size();
            for (int i = 0; i < cur_size; i++)
            {
                Node* cur_node = que.front();
                que.pop();

                if (cur_node->left != nullptr) {
                    que.push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    que.push(cur_node->right);
                }
                if (i == cur_size - 1) {
                    cur_node->next = nullptr;
                }
                else {
                    cur_node->next = que.front();
                }
            }
        }

        return root;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间14ms, 击败64.72% c++用户
* 消耗内存17.34M, 击败28.07% c++用户
*/
