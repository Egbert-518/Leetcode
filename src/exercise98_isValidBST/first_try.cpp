/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：
    节点的左子树只包含 小于 当前节点的数。
    节点的右子树只包含 大于 当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

示例 1：
    输入：root = [2,1,3]
    输出：true

示例 2：
    输入：root = [5,1,4,null,null,3,6]
    输出：false
    解释：根节点的值是 5 ，但是右子节点的值是 4 。


树中节点数目范围在[1, 10^4] 内
-2^31 <= Node.val <= 2^31 - 1

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
    bool isValidBST(TreeNode* root) {
        /*二叉搜索树的中序遍历一定是一个递增数组, 本次先复习一下中序遍历, 后面第二次做时再想想如何递归*/
        vector<int> nums;
        traversal(root, nums);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }

        return true;
    }

    void traversal(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            traversal(root->left, nums);     // 左
        }
        nums.emplace_back(root->val);        // 中
        if (root->right != nullptr) {
            traversal(root->right, nums);    // 右
        }
    }
};

int main()
{

    return 0;
}

/*
* 运行时间3ms, 击败97.85% c++用户
* 消耗内存19.90M, 击败95.37 c++用户
*/
