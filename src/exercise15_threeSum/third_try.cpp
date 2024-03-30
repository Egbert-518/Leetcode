/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。


示例 1：
    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
    解释：
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
    不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
    注意，输出的顺序和三元组的顺序并不重要。

示例 2：
    输入：nums = [0,1,1]
    输出：[]
    解释：唯一可能的三元组和不为 0 。

示例 3：
    输入：nums = [0,0,0]
    输出：[[0,0,0]]
    解释：唯一可能的三元组和为 0 。

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first = INT32_MIN;
        std::vector<std::vector<int>> results;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0) {   // 剪枝
                break;
            }
            if (nums[i] == first) {   // 如果与上一层外循环数字相同, 则不进行本次查找
                continue;
            }
            first = nums[i];    // 不相同, 更新first


            // 确定起始点以及数值后, 对剩余的数组使用双指针, 判断和与0的大小
            int j = i + 1, k = nums.size() - 1;
            for (; j < k;)
            {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    results.push_back({ nums[i], nums[j], nums[k] });

                    int third = nums[k];
                    while (k >= 0 && nums[k] == third)
                    {
                        k--;
                    }

                    int second = nums[j];
                    while (j < nums.size() && nums[j] == second)
                    {
                        j++;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    // 大了, 说明需要将k减小
                    int third = nums[k];
                    while (k >= 0 && nums[k] == third)
                    {
                        k--;
                    }
                }
                else {
                    // 小了, 说明需要将j增大
                    int second = nums[j];
                    while (j < nums.size() && nums[j] == second)
                    {
                        j++;
                    }
                }
            }
        }

        return results;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = { 0, 0, 0 };
    solution.threeSum(nums);
    return 0;
}

/*
* 运行时间81ms, 击败38.24% c++用户
* 消耗内存26.63M, 击败29.93% c++用户
*/
