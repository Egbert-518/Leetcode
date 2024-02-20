/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
    输入：nums = [0,1]
    输出：[[0,1],[1,0]]

1 <= nums.length <= 6
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*本道题是全排列1, 不含重复数字, 下一道全排列2肯定就含重复数字了*/
        path.clear();
        results.clear();
        vector<bool> is_used(nums.size(), false);
        backtracking(nums, is_used);
        return results;
    }

    void backtracking(vector<int>& nums, vector<bool>& is_used) {
        if (path.size() == nums.size()) {
            results.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (is_used[i]) {
                // 如果这个元素被使用过
                continue;
            }
            else {
                path.emplace_back(nums[i]);
                is_used[i] = true;
                backtracking(nums, is_used);
                is_used[i] = false;
                path.pop_back();
            }
        }
    }

private:
    vector<int> path;
    vector<vector<int>> results;
};


int main()
{
    Solution solution;
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> results = solution.permute(nums);

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
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存9.69M, 击败10.76% c++用户
*/
