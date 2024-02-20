/*
给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

示例 1：
    输入：root = [1,null,3,2,4,null,5,6]
    输出：[1,3,5,6,2,4]

节点总数在范围 [0, 10^4]内
0 <= Node.val <= 10^4
n 叉树的高度小于或等于 1000

进阶：递归法很简单，你可以使用迭代法完成此题吗?
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        /*先用递归法试一下*/
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal(Node* root, vector<int>& result) {
        /*递归法所需要用到的函数*/
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
        {
            traversal(root->children[i], result);
        }
    }

    vector<int> iter_preorder(Node* root) {
        /*再尝试使用迭代法, 迭代法的主要思想是要用到栈*/
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        std::stack<Node*> stack_tree;
        stack_tree.push(root);

        while (!stack_tree.empty())
        {
            Node* node = stack_tree.top();
            stack_tree.pop();
            if (node != nullptr) {
                // 输出中左右的顺序, 入栈需要为右左中
                for (int i = node->children.size() - 1; i >= 0; i--)
                {
                    if (node->children[i] != nullptr) {
                        stack_tree.push(node->children[i]);
                    }
                }
                stack_tree.push(node);
                stack_tree.push(nullptr);    // 统一模板下, 遇到中节点则放入nullptr
            }
            else {    // 遇到nullptr开始读取
                Node* top = stack_tree.top();
                stack_tree.pop();
                result.push_back(top->val);
            }
        }

        return result;
    }
};


int main()
{

    return 0;
}

/*
* 运行时间20ms, 击败46.70% c++用户
* 消耗内存11.81M, 击败27.46% c++用户
*/
