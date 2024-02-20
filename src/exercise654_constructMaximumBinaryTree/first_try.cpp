/*
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
    创建一个根节点，其值为 nums 中的最大值。
    递归地在最大值 左边 的 子数组前缀上 构建左子树。
    递归地在最大值 右边 的 子数组后缀上 构建右子树。
    返回 nums 构建的 最大二叉树 。

示例 1：
    输入：nums = [3,2,1,6,0,5]
    输出：[6,3,5,null,2,0,null,null,1]
    解释：递归调用如下所示：
    - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
        - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
            - 空数组，无子节点。
            - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
                - 空数组，无子节点。
                - 只有一个元素，所以子节点是一个值为 1 的节点。
        - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
            - 只有一个元素，所以子节点是一个值为 0 的节点。
            - 空数组，无子节点。


1 <= nums.length <= 1000
0 <= nums[i] <= 1000
nums 中的所有整数 互不相同

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }

        int max_values = INT32_MIN, kk = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max_values) {
                max_values = nums[i];
                kk = i;
            }
        }

        TreeNode* root = new TreeNode(max_values);
        vector<int> left_nums(nums.begin(), nums.begin() + kk);
        vector<int> right_nums(nums.begin() + kk + 1, nums.end());
        root->left = constructMaximumBinaryTree(left_nums);
        root->right = constructMaximumBinaryTree(right_nums);

        return root;
    }
};

int main()
{

    return 0;
}

/*
* 运行时间88ms, 击败45.11% c++用户
* 消耗内存51.76M, 击败41.58% c++用户
*/
