/*
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。


示例 1：
    输入：root = [4,2,7,1,3], val = 2
    输出：[2,1,3]

示例 2：
    输入：root = [4,2,7,1,3], val = 5
    输出：[]


树中节点数在 [1, 5000] 范围内
1 <= Node.val <= 10^7
root 是二叉搜索树
1 <= val <= 10^7

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
    TreeNode* searchBST(TreeNode* root, int val) {
        /*二叉搜索树, 比根节点大的值会放在右边, 比根节点小的值会放在左边*/
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        }
        else if (root->val > val) {
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }
    }
};

int main()
{

    return 0;
}

/*
* 运行时间42ms, 击败23.44% c++用户
* 消耗内存32.35M, 击败99.45 c++用户
*/
