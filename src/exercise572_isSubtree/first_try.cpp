/*
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

示例 1：
    输入：root = [3,4,5,1,2], subRoot = [4,1,2]
    输出：true

示例 2：
    输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    输出：false

root 树上的节点数量范围是 [1, 2000]
subRoot 树上的节点数量范围是 [1, 1000]
-10^4 <= root.val <= 10^4
-10^4 <= subRoot.val <= 10^4

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /*利用之前判断是否相同的两棵树, 遍历root的所有节点, 看是否能找到和subRoot一样的树*/
        if (root == nullptr) {
            return false;   // 因为节点数至少为1
        }
        bool mid_result = isSameSubTree(root, subRoot);
        if (mid_result) {
            return true;
        }
        else {
            return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        }

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

    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(1, a, nullptr);
    TreeNode* c = new TreeNode(1, nullptr, b);
    TreeNode* d = new TreeNode(1, nullptr, c);
    TreeNode* e = new TreeNode(1, nullptr, d);
    TreeNode* f = new TreeNode(1, nullptr, e);
    TreeNode* g = new TreeNode(1, nullptr, f);

    TreeNode* h = new TreeNode(1, nullptr, g);
    TreeNode* i = new TreeNode(1, nullptr, h);
    TreeNode* j = new TreeNode(1, nullptr, i);
    TreeNode* k = new TreeNode(1, nullptr, j);
    TreeNode* l = new TreeNode(1, nullptr, k);

    Solution solution;
    bool result = solution.isSubtree(i, g);
    if (result) {
        std::cout << "is sub tree\n";
    }
    else {
        std::cout << "is not sub tree";
    }

    return 0;
}

/*
* 运行时间32ms, 击败16.83% c++用户
* 消耗内存27.15M, 击败99.56% c++用户
*/
