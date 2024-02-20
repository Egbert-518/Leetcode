/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
    输入：nums = [1,2,3]
    输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

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
        path.clear();
        results.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return results;
    }

    void backtracking(vector<int>& nums, int startIndex) {
        // 不需要循环, 只需要判断每个元素取或是不取, 但需要注意的是, 由于相同元素的存在, 因此子集可能重复, 需要将这些重复子集去除
        if (startIndex >= nums.size()) {
            results.emplace_back(path);
            return;
        }

        // 当前元素取
        path.emplace_back(nums[startIndex]);
        backtracking(nums, startIndex + 1);
        path.pop_back();

        // 当前元素不取, 则不需要pop_back, 且不需要对同层树进行排除
        backtracking(nums, startIndex + 1);

    }

private:
    vector<int> path;
    vector<vector<int>> results;
};


int main()
{

    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存8.21M, 击败19.02% c++用户
*/
