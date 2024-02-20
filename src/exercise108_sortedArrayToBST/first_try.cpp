/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

示例 1：
    输入：nums = [-10,-3,0,5,9]
    输出：[0,-3,9,-10,null,5]
    解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案

示例 2：
    输入：nums = [1,3]
    输出：[3,1]
    解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums 按 严格递增 顺序排列
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        /*每次找中间元素作为中间节点, 能够保证事平衡树*/
        return customSortArrayToBST(nums, 0, nums.size());
    }

    TreeNode* customSortArrayToBST(vector<int>& nums, int begin, int end) {
        if (begin == end) {
            return nullptr;
        }

        int delimiter = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[delimiter]);
        root->left = customSortArrayToBST(nums, begin, delimiter);    // 不包含delimiter
        root->right = customSortArrayToBST(nums, delimiter + 1, end);

        return root;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = { 1,3 };

    TreeNode* root = solution.sortedArrayToBST(nums);
    return 0;
}

/*
* 运行时间11ms, 击败65.40% c++用户
* 消耗内存20.38M, 击败92.49% c++用户
*/
