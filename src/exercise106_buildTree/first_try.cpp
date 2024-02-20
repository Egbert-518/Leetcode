/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

示例 1：
    输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    输出：[3,9,20,null,null,15,7]


1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*后序遍历的最后一位是当前的根节点, 在中序遍历中可以通过查找这个值来区分左右子树(因为vector中的值两两不同), 递归将左、右树的中后序遍历输入*/
        if (postorder.size() == 0) {
            return nullptr;
        }

        int root_val = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(root_val);

        if (postorder.size() == 1) {
            return root;
        }

        int kk = 0;
        for (; kk < inorder.size(); kk++)
        {
            if (inorder[kk] == root_val) {
                break;
            }
        }

        // kk 处的值为root_val, 即对于中序遍历数组而言[0, kk-1]为左树, [kk+1, size-1]是右树, 对于后序遍历来说, [0, kk-1]为左树,[kk, size-2]为右树
        // 根据迭代器创建新的vector
        vector<int> left_inorder(inorder.begin(), inorder.begin() + kk - 1 + 1);    // 从迭代器构造是不包含末尾的, 所以在上述闭区间基础上进行了+1
        vector<int> left_postorder(postorder.begin(), postorder.begin() + kk - 1 + 1);
        root->left = buildTree(left_inorder, left_postorder);

        // 
        vector<int> right_inorder(inorder.begin() + kk + 1, inorder.end());     // end本身就指向了这个vector最后一位有效元素的后一位, 因此在此不需要+1
        vector<int> right_postorder(postorder.begin() + kk, postorder.end() - 1);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
};

int main()
{
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };

    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);
    return 0;
}

/*
* 运行时间36ms, 击败37.13% c++用户
* 消耗内存71.95M, 击败43.24% c++用户
*/
