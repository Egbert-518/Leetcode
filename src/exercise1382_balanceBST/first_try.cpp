/*
给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。

如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。

示例1:
    输入：root = [1,null,2,null,3,null,4,null,null]
    输出：[2,1,3,null,null,null,4]
    解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。

示例 2：
    输入: root = [2,1,3]
    输出: [2,1,3]


树节点的数目在 [1, 10^4] 范围内。
1 <= Node.val <= 10^5
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


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        /*因为是二叉搜索树, 所以先通过中序遍历获取有序数组*/
        vector<int> vec;
        traversal(root, vec);
        return constructBST(vec, 0, vec.size() - 1);
    }

    void traversal(TreeNode* root, vector<int>& vec) {
        if (root->left != nullptr) {
            traversal(root->left, vec);
        }
        vec.emplace_back(root->val);
        if (root->right != nullptr) {
            traversal(root->right, vec);
        }
    }

    TreeNode* constructBST(vector<int>& vec, int left, int right) {
        if (left > right) {
            return nullptr;    // [left, right]闭区间
        }

        int mid = (right + left) / 2;    // 如果节点数特别多时, 可以写left + (right - left) / 2来避免int长度超标
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = constructBST(vec, left, mid - 1);
        root->right = constructBST(vec, mid + 1, right);
        return root;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间107ms, 击败65.44% c++用户
* 消耗内存61.19M, 击败72.55% c++用户
*/
