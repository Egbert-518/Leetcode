/*
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：
    例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。

示例1:
    输入：root = [1,2,3]
    输出：25
    解释：
    从根到叶子节点路径 1->2 代表数字 12
    从根到叶子节点路径 1->3 代表数字 13
    因此，数字总和 = 12 + 13 = 25

示例 2：
    输入：root = [4,9,0,5,1]
    输出：1026
    解释：
    从根到叶子节点路径 4->9->5 代表数字 495
    从根到叶子节点路径 4->9->1 代表数字 491
    从根到叶子节点路径 4->0 代表数字 40
    因此，数字总和 = 495 + 491 + 40 = 1026


树中节点的数目在范围 [1, 1000] 内
0 <= Node.val <= 9
树的深度不超过 10
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
    int sumNumbers(TreeNode* root) {
        /*层序遍历即可*/
        int sum = 0;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            int cur_size = que.size();    // 当前层的节点个数
            for (int i = 0; i < cur_size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left != nullptr && cur->right != nullptr) {
                    cur->left->val = cur->val * 10 + cur->left->val;
                    cur->right->val = cur->val * 10 + cur->right->val;
                    que.push(cur->left);
                    que.push(cur->right);
                }
                else if (cur->left != nullptr) {
                    cur->left->val = cur->val * 10 + cur->left->val;
                    que.push(cur->left);
                }
                else if (cur->right != nullptr) {
                    cur->right->val = cur->val * 10 + cur->right->val;
                    que.push(cur->right);
                }
                else {
                    // 均为空, 则到叶子节点
                    sum += cur->val;
                }
            }
        }
        return sum;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间3ms, 击败45.73% c++用户
* 消耗内存10.89M, 击败11.47% c++用户
*/
