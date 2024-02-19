/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。

判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。

输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按 升序 排列

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_num = nums[0];  // 第一个元素
        vector<int> diff_idx = {0};   // 存储不同元素的下标

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != cur_num) {
                diff_idx.emplace_back(i);
                cur_num = nums[i];
            }
        }

        for (int i = 0; i < diff_idx.size(); i++) {
            nums[i] = nums[diff_idx[i]];
        }

        return diff_idx.size();
    }
};


int main() {
    vector<int> nums{ 0,0,1,1,1,2,2,3,3,4 };
    Solution solution;

    int k = solution.removeDuplicates(nums);
    std::cout << k << "\n";

    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }

    return 0;
}


/*
* 执行用时：8 ms, 在所有 C++ 提交中击败了85.04%的用户
* 内存消耗：17.72MB, 在所有 C++ 提交中击败了5.63%的用户
*/

