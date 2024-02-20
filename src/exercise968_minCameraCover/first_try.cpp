/*
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

示例 1：
    输入：[0,0,null,0,0]
    输出：1
    解释：如图所示，一台摄像头足以监控所有节点。

示例 2:
    输入：[0,0,null,0,null,0,null,null,0]
    输出：2
    解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。


给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};


class Solution {
public:
    int minCameraCover(TreeNode* root) {
        /*叶子节点之上需要放摄像头, 此后每隔两个节点放一个, 每个节点只可能有三种状态中的一个, 0: 无覆盖, 1: 有摄像头, 2: 有覆盖*/
        result = 0;
        if (traversal(root) == 0) {
            result++;    // root无覆盖
        }
        return result;
    }

    int traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return 2;   // 空节点, 置为有覆盖
        }

        int left = traversal(cur->left);      // 左右中, 后序遍历
        int right = traversal(cur->right);

        // 情况1, 左右节点都有覆盖
        if (left == 2 && right == 2) {
            return 0;   // 当前节点无覆盖
        }

        // 情况2, 左右节点中至少一个无覆盖
        if (left == 0 || right == 0) {
            result++;
            return 1;    // 添加摄像头
        }

        // 情况3, 左右节点中至少有一个有摄像头
        if (left == 1 || right == 1) {
            return 2;   // 当前节点有覆盖
        }

        return -1;    // 不会走到这, 但需要一个返回值
    }

private:
    int result;
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间12ms, 击败38.43% c++用户
* 消耗内存19.54M, 击败85.97% c++用户
*/
