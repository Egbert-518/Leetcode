/*
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1：
    输入：root = [3,9,20,null,null,15,7]
    输出：true

示例 2：
    输入：root = []
    输出：true

树中的节点数在范围 [0, 5000] 内
-10^4 <= Node.val <= 10^4
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
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
    bool isBalanced(TreeNode* root) {

    }
};


int main()
{
    /*TreeNode* layer31 = new TreeNode(4);
    TreeNode* layer32 = new TreeNode(5);
    TreeNode* layer33 = new TreeNode(6);

    TreeNode* layer21 = new TreeNode(2, layer31, layer32);
    TreeNode* layer22 = new TreeNode(3, layer33, nullptr);*/

    TreeNode* layer31 = new TreeNode(4);
    TreeNode* layer21 = new TreeNode(2, layer31, nullptr);
    TreeNode* layer22 = new TreeNode(3);
    TreeNode* layer11 = new TreeNode(1, layer21, layer22);


    return 0;
}

/*
* 运行时间32ms, 击败47.70% c++用户
* 消耗内存30.44M, 击败53.06% c++用户
*/
