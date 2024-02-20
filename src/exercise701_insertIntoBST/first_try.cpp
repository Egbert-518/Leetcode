/*
给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

示例 1：
    输入：root = [4,2,7,1,3], val = 5
    输出：[4,2,7,1,3,5]

示例 2：
    输入：root = [40,20,60,10,30,50,70], val = 25
    输出：[40,20,60,10,30,50,70,null,null,25]

树中的节点数将在 [0, 10^4]的范围内。
-10^8 <= Node.val <= 10^8
所有值 Node.val 是 独一无二 的。
-10^8 <= val <= 10^8
保证 val 在原始BST中不存在。
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }

        TreeNode* node = root;
        while (node != nullptr) {
            if (val < node->val) {
                // 应当向左查找, 如果左节点为空, 直接插入
                if (node->left != nullptr) {
                    node = node->left;
                }
                else {
                    node->left = new TreeNode(val);
                    break;
                }
            }
            else {
                if (node->right != nullptr) {
                    node = node->right;
                }
                else {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};


int main()
{

    return 0;
}

/*
* 运行时间66ms, 击败90.90% c++用户
* 消耗内存54.84M, 击败94.00 c++用户
*/
