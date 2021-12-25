/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。


3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int gap = INT32_MAX;
        int result = target;

        sort(nums.begin(), nums.end());  // 从小到大排序
        for (auto first = nums.begin(); first != nums.end(); first++) {
            auto second = first + 1;
            auto third = nums.end() - 1;
            while (second < third) {
                int value = *first + *second + *third - target;
                int sign = (value >= 0 ? 1 : -1);
                value *= sign;
                if (value < gap) {
                    gap = value;
                    result = target + gap * sign;
                }
                if (sign == 1) {
                    third--;
                }
                else {
                    second++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { -1, 2, 1, -4 };
    int target = 2;
    int result = solution.threeSumClosest(nums, target);
    cout << result << endl;
    return 0;
}

/*
* 执行用时：4 ms, 在所有 C++ 提交中击败了98.01%的用户
* 内存消耗：9.7MB, 在所有 C++ 提交中击败了22.51%的用户
* 通过测试用例：131 / 131
*/
