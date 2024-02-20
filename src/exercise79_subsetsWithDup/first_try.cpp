/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：
    输入：nums = [1,2,2]
    输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
    输入：nums = [0]
    输出：[[],[0]]

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*在代码随想录中属于回溯法, 但想不到终止条件是什么, 因为题目length最大为10, 十层for循环应该也不难, 但是数学思想上来说, 就是每个值取或不取*/
        /*换个角度想, 或许终止条件就是回溯到结果size为2^n, 回溯就是回溯到当前这个值取或是不取, 仔细想想终止条件应该是startIndex到nums的末尾*/
        first_entry = true;
        path.clear();
        results.clear();
        vector<bool> is_used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, is_used);
        return results;
    }

    void backtracking(vector<int>& nums, int startIndex, vector<bool> is_used) {
        // 不需要循环, 只需要判断每个元素取或是不取, 但需要注意的是, 由于相同元素的存在, 因此子集可能重复, 需要将这些重复子集去除
        if (startIndex >= nums.size()) {
            results.emplace_back(path);
            return;
        }
        // 针对重复元素的取法, 我们来看以下规律, 如1 2 2 2, 可以有1 2, 1 2 2, 1 2 2 2, 但是2来自哪里不知道
        // 所以我们规定, 只有当前面的2被使用时, 此时的2才能够被取, 否则不能被取

        // 首先判断当前元素是否使用
        if (first_entry) {
            // 第一次进入, 不能够判断前面的元素
            // 当前元素取
            first_entry = false;
            path.emplace_back(nums[startIndex]);
            is_used[startIndex] = true;
            backtracking(nums, startIndex + 1, is_used);
            is_used[startIndex] = false;
            path.pop_back();

            // 当前元素不取, 则不需要pop_back
            backtracking(nums, startIndex + 1, is_used);
        }

        else {
            if (nums[startIndex] == nums[startIndex - 1]) {
                if (is_used[startIndex - 1]) {
                    // 如果前面的数字被使用, 这个数字才能够被使用
                    // 当前元素取
                    first_entry = false;
                    path.emplace_back(nums[startIndex]);
                    is_used[startIndex] = true;
                    backtracking(nums, startIndex + 1, is_used);
                    is_used[startIndex] = false;
                    path.pop_back();

                    // 当前元素不取, 则不需要pop_back
                    backtracking(nums, startIndex + 1, is_used);
                }
                else {
                    // 否则, 当前元素一定不能被选取
                    backtracking(nums, startIndex + 1, is_used);
                }
            }

            else {
                // 当前元素与先前元素不相同, 无所谓可取也可不取
                // 当前元素取
                first_entry = false;
                path.emplace_back(nums[startIndex]);
                is_used[startIndex] = true;
                backtracking(nums, startIndex + 1, is_used);
                is_used[startIndex] = false;
                path.pop_back();

                // 当前元素不取, 则不需要pop_back
                backtracking(nums, startIndex + 1, is_used);
            }
        }
    }

private:
    vector<int> path;
    vector<vector<int>> results;
    bool first_entry;
};


int main()
{
    Solution solution;
    vector<int> nums = { 1, 2, 2 };
    vector<vector<int>> results = solution.subsetsWithDup(nums);
    for (vector<int> result : results)
    {
        for (int element : result)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
* 运行时间3ms, 击败56.39% c++用户
* 消耗内存15.22M, 击败5.01% c++用户
*/
