/*
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1：
    输入：p = [1,2,3], q = [1,2,3]
    输出：true

示例 2：
    输入：p = [1,2], q = [1,null,2]
    输出：false

两棵树上的节点数目都在范围 [0, 100] 内
-10^4 <= Node.val <= 10^4

*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left{ nullptr }, right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 首先要确定递归返回的条件
        return isSameSubTree(p, q);
    }

    bool isSameSubTree(TreeNode* p_sub, TreeNode* q_sub) {
        if (p_sub == nullptr && q_sub == nullptr) {
            return true;
        }
        else if (p_sub == nullptr && q_sub != nullptr) {
            return false;
        }
        else if (p_sub != nullptr && q_sub == nullptr) {
            return false;
        }
        else {
            // 都为非空
            if (p_sub->val != q_sub->val) {   // 中
                return false;
            }
            bool left_result = isSameSubTree(p_sub->left, q_sub->left);   // 左
            bool right_result = isSameSubTree(p_sub->right, q_sub->right);   // 右
            return (left_result && right_result);
        }
    }
};


int main()
{


    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存11.49M, 击败5.10% c++用户
*/
