/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

示例 1：
    输入：nums = [4,6,7,7]
    输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

示例 2：
    输入：nums = [4,4,3,2,1]
    输出：[[4,4]]

1 <= nums.length <= 15
-100 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        results.clear();
        backtracking(nums, 0);
        return results;
    }

    void backtracking(vector<int>& nums, int startIndex) {
        /*同一层的元素不能取相同的, 不同层的元素可以取相同的, 取完之后取该元素之后的*/
        if (path.size() >= 2) {
            results.emplace_back(path);   // 这里不return, 因为还会继续添加
        }

        bool is_used[201] = { false };   // 因为数字范围为[-100, 100], 使用一个大小为201的数组来确定本层数值是否被使用, 用空间换取unordered_set的nlogn查询时间
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) || is_used[nums[i] + 100]) {
                continue;    // 如果当前的元素小于path的末尾元素, 或者当前元素在之前已经被使用过, 则一定不添加
            }

            path.emplace_back(nums[i]);
            is_used[nums[i] + 100] = true;
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

private:
    vector<int> path;
    vector<vector<int>> results;
};


int main()
{
    Solution solution;
    vector<int> nums = { 4, 6, 7, 7 };
    vector<vector<int>> results = solution.findSubsequences(nums);

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
* 运行时间27ms, 击败92.96% c++用户
* 消耗内存21.86M, 击败76.73% c++用户
*/
