/*
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
如果树中有不止一个众数，可以按 任意顺序 返回。

假定 BST 满足如下定义：
    结点左子树中所含节点的值 小于等于 当前节点的值
    结点右子树中所含节点的值 大于等于 当前节点的值
    左子树和右子树都是二叉搜索树

示例 1：
    输入：root = [1,null,2,2]
    输出：[2]


树中节点的数目在范围 [1, 10^4] 内
-10^5 <= Node.val <= 10^5

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    vector<int> findMode(TreeNode* root) {
        /*直接尝试不使用额外空间, 中序遍历, 记录当前最大出现相同值的次数, 如果新的出现相同次数与之相等, 则将该值直接push, 如果超过, 则将现数组清空, 将该值push*/
        vector<int> nums;
        traversal(root, nums);

        return nums;
    }

    void traversal(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }

        std::stack<TreeNode*> tree_stack;
        tree_stack.push(root);
        bool first_entry = true;
        int max_count = 0, cur_count = 0, last_val = 0;
        while (!tree_stack.empty())
        {
            TreeNode* node = tree_stack.top();
            tree_stack.pop();
            if (node != nullptr) {
                if (node->right != nullptr) {
                    tree_stack.push(node->right);
                }

                tree_stack.push(node);
                tree_stack.push(nullptr);

                if (node->left != nullptr) {
                    tree_stack.push(node->left);
                }
            }
            else {
                TreeNode* top = tree_stack.top();
                tree_stack.pop();

                if (first_entry) {
                    first_entry = false;
                    cur_count++;
                    last_val = top->val;   // 第一次进来后的状态是, 最大连续长度0, 当前连续长度1, 众数中不保留值, 如果整个数组都一样, 会在遍历完添加
                }
                else {
                    if (top->val == last_val) {
                        // 如果当前值与上一个值相同
                        cur_count++;
                    }
                    else {
                        // 如果不同, 则要比较当前连续长度与最大连续长度
                        if (cur_count > max_count) {
                            max_count = cur_count;   // cur_count不包括当前这个值的长度
                            nums.clear();
                            nums.emplace_back(last_val);
                        }
                        else if (cur_count == max_count) {
                            // 如果与之前最长长度等长
                            nums.emplace_back(last_val);
                        }
                        // 比之前小, 则不做操作, 整体都需要清空当前计数, 以及为last_val赋值
                        cur_count = 1;  // 清空, 但需要为当前这个值计数
                        last_val = top->val;
                    }
                }
            }
        }

        // 遍历到最后一位时, 需要与当前的最大长度值情况进行比较
        if (nums.empty() || nums.back() != last_val) {
            if (cur_count > max_count) {
                nums.clear();
                nums.emplace_back(last_val);
            }
            else if (cur_count == max_count) {
                nums.emplace_back(last_val);
            }
        }
    }
};

int main()
{

    return 0;
}

/*
* 运行时间8ms, 击败98.58% c++用户
* 消耗内存21.82M, 击败98.58 c++用户
*/
