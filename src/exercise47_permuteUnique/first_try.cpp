/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：
    输入：nums = [1,1,2]
    输出：
    [[1,1,2],
     [1,2,1],
     [2,1,1]]

示例 2：
    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*本题数组元素可以重复, 因此需要去重, 去重则排序, 同层树不取相同元素, 同一分支可取相同树*/
        path.clear();
        results.clear();
        sort(nums.begin(), nums.end());
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
            if (i >= 1 && nums[i] == nums[i - 1] && is_used[i - 1] == false) {    // 这里is_used[i-1]==false是同一数层内去重, 对于排列来说, 也可以写is_used[i-1]==true是同一树枝去重, 但是前者更高效; 不过不能不写, 表示要么一直为true或一直false, 不能一会true一会false
                continue;    // 同一层内, 如果该元素与前一元素相同, 则跳过
            }
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
    vector<int> nums = { 1, 1, 1, 2 };
    vector<vector<int>> results = solution.permuteUnique(nums);

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
* 运行时间7ms, 击败64.46% c++用户
* 消耗内存11.16M, 击败20.67% c++用户
*/
