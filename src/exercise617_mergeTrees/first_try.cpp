/*
给你两棵二叉树： root1 和 root2 。
想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。
注意: 合并过程必须从两个树的根节点开始。

示例 1：
    输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
    输出：[3,4,5,5,4,null,7]

两棵树中的节点数目在范围 [0, 2000] 内
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        /*这个过程是可交换的, 即无论以root1还是root2为参考, 结果是一样的*/
        /*考虑递归, 对当前节点进行数值加和, 随后当前节点的left应当等于树1当前节点的left与树2当前节点的left进行merge, 当其中一方为空时, 直接返回另一棵树在此的情况*/
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

int main()
{

    return 0;
}

/*
* 运行时间30ms, 击败59.73% c++用户
* 消耗内存31.44M, 击败99.20% c++用户
*/
