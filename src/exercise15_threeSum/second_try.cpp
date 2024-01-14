/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例1：
    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
    解释：
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
    不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
    注意，输出的顺序和三元组的顺序并不重要。

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*这里不能返回重复的三元组, 尝试过使用unordered_multimap构建hash表, 但这样只能做到返回下标不重复的三元组, 对于元素不重复, 去重比较困难*/
        /*因此考虑双指针法*/

        sort(nums.begin(), nums.end());   // 需要先排序
        vector<vector<int>> outputs;
        for (int i = 0; i < nums.size(); )   // 先不给出i的移动情况
        {
            if (nums[i] > 0) {
                return outputs;    // 首位>0, 提前结束, 节省计算
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right)   // 这里不取等号, 因为left == right不应有定义
            {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    vector<int> output = { nums[i], nums[left], nums[right] };
                    outputs.emplace_back(output);

                    // 移动right和left直到指向第一个非相同的元素
                    int right_val = nums[right];
                    while (right >= 0 && nums[right] == right_val)
                    {
                        right--;
                    }
                    int left_val = nums[left];
                    while (left < nums.size() && nums[left] == left_val)
                    {
                        left++;
                    }
                }
                else if (nums[i] + nums[left] + nums[right] > 0) {  // 如果和太大了, 应该让right右移, 需要注意重复元素
                    int right_val = nums[right];
                    while (right >= 0 && nums[right] == right_val)
                    {
                        right--;
                    }
                }
                else {  // 如果和太小了, 应该让right右移, 需要注意重复元素
                    int left_val = nums[left];
                    while (left < nums.size() && nums[left] == left_val)
                    {
                        left++;
                    }
                }
            }

            // 对这个位置的遍历结束, 至多遍历数组1遍, 紧接着对i移动, 也要考虑重复元素
            int cur_val = nums[i];
            while (i < nums.size() && nums[i] == cur_val)
            {
                i++;
            }
        }
        return outputs;
    }
};


int main() 
{
    Solution solutin;
    vector<int> nums = { 0,0,0 };
    solutin.threeSum(nums);

    return 0;
}

/*
* 运行时间224ms, 击败12.40％ c++用户
* 消耗内存25.71M, 击败15.30% c++用户
*/
