/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。

示例 1：
    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    输出:
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]

示例 2：
    输入: candidates = [2,5,2,1,2], target = 5,
    输出:
    [
    [1,2,2],
    [5]
]

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*注意与组合总和1不同, 这里的candidates元素是有重复的, 如果将当前元素以后的元素作为子集可以吗, 似乎是不行的, 因为比如示例1中如果target是12的话, 1 6 5和6 1 5都是可能被取到的, 但它们重复*/
        /*我想的是先对candidates进行排序, 使相同元素在一起, 然后在每一层搜索时, 如果放入的元素与candidates中上一个相同, 那么就不对它进行搜索*/
        /*这与代码随想录中说的, 同一层树所选数字不能重复, 但同一树枝上的数字可以重复的思想是一致的!*/
        results.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return results;
    }

    void backtracking(vector<int>& candidates, int target, int sum, int start_idx) {
        // 传入这里的candidates已经经过从小到大排序
        if (sum > target) {
            return;
        }
        if (sum == target) {
            results.emplace_back(path);
            return;
        }

        int last_num = 0;   // 因为candidates的值在1-50之间, 所以不会等于0
        for (int i = start_idx; i < candidates.size(); i++)
        {
            if (candidates[i] != last_num) {
                // 只有当前值与之前不相同的时候才进行回溯
                sum = sum + candidates[i];
                path.emplace_back(candidates[i]);
                backtracking(candidates, target, sum, i + 1);   // 当前这位数字不能重复使用
                sum = sum - candidates[i];
                path.pop_back();
                last_num = candidates[i];   // 更新last_num, 这是同一层, 下次进入时如果与这个元素相同则不会回溯, 直到与之不同
            }
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
* 运行时间3ms, 击败90.63% c++用户
* 消耗内存12.54M, 击败26.34% c++用户
*/
