/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

示例1:
    输入：nums = [5,7,7,8,8,10], target = 8
    输出：[3,4]

示例 2：
    输入：nums = [5,7,7,8,8,10], target = 6
    输出：[-1,-1]

示例 3：
    输入：nums = [], target = 0
    输出：[-1,-1]

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums 是一个非递减数组
-10^9 <= target <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // o(logn)需要用二分法
        int low = 0, high = nums.size() - 1;   // 要确定区间开闭, 这里采用[low, high], 即两边都有意义
        while (low <= high)   // 等号有意义
        {
            int mid = (low + high) / 2;
            if (target > nums[mid]) {
                low = mid + 1;
            }
            else if (target < nums[mid]) {
                high = mid - 1;
            }
            else {
                // 找到了, nums[mid] == target
                low = mid;
                high = mid;
                break;
            }
        }

        if (low > high) {
            return { -1, -1 };
        }
        else {
            for (; high < nums.size(); high++)
            {
                if (nums[high] != target) {
                    break;
                }
            }
            for (; low >= 0; low--)
            {
                if (nums[low] != target) {
                    break;
                }
            }
            return { low + 1, high - 1 };
        }
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间7ms, 击败59.34% c++用户
* 消耗内存15.71M, 击败24.10% c++用户
*/
