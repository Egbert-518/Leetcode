/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

示例 1：
    输入：root = [3,9,20,null,null,15,7]
    输出：[[3],[9,20],[15,7]]

树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*队列的先入先出特性适合广度搜索, 栈的先入后出特性适合深度搜索*/
        deque<TreeNode*> queue;
        vector<vector<int>> outputs;
        if (root != nullptr) {
            queue.push_back(root);
        }
        while (!queue.empty())
        {
            int cur_size = queue.size();
            vector<int> output;
            for (int i = 0; i < cur_size; i++)    // 当前层的个数
            {
                output.push_back(queue.front()->val);    // 会将当前层的值存入
                if (queue.front()->left != nullptr) {
                    queue.push_back(queue.front()->left);     // 存入下一层非空的指针, 即当前层所有节点的左右节点
                }
                if (queue.front()->right != nullptr) {
                    queue.push_back(queue.front()->right);
                }
                queue.pop_front();
            }
            outputs.push_back(output);
        }

        return outputs;
    }
};


int main()
{

    return 0;
}

/*
* 运行时间4ms, 击败87.23% c++用户
* 消耗内存13.82M, 击败18.09% c++用户
*/
