/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
对于给定的输入，保证和为 target 的不同组合数少于 150 个。

示例 1：
    输入：candidates = [2,3,6,7], target = 7
    输出：[[2,2,3],[7]]
    解释：
    2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
    7 也是一个候选， 7 = 7 。
    仅有这两种组合。

示例 2：
    输入: candidates = [2,3,5], target = 8
    输出: [[2,2,2,2],[2,3,3],[3,5]]

示例 3：
    输入: candidates = [2], target = 1
    输出: []

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
candidates 的所有元素 互不相同
1 <= target <= 40
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        results.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return results;
    }

    void backtracking(vector<int>& candidates, int target, int sum, int start_idx) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            results.emplace_back(path);
            return;
        }

        for (int i = start_idx; i < candidates.size(); i++)
        {
            sum = sum + candidates[i];
            path.emplace_back(candidates[i]);
            backtracking(candidates, target, sum, i);   // 不需要写i + 1, 因为当前数是可以重复读的
            sum = sum - candidates[i];   // 回溯, 从这个节点的某个子集换到另一个子集, 所以要对子集的操作进行删除
            path.pop_back();
        }
    }

private:
    vector<vector<int>> results;
    vector<int> path;
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间6ms, 击败51.93% c++用户
* 消耗内存12.20M, 击败34.68% c++用户
*/
