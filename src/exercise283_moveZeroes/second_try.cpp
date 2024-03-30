/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。


示例 1：
    输入: nums = [0,1,0,3,12]
    输出: [1,3,12,0,0]

示例 2：
    输入: nums = [0]
    输出: [0]

1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

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
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        for (; fast < nums.size();)
        {
            while (fast < nums.size() && nums[fast] == 0)
            {
                fast++;
            }
            if (fast < nums.size()) {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        for (; slow < nums.size(); slow++)
        {
            nums[slow] = 0;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = { 0, 1, 0 };
    solution.moveZeroes(nums);
    return 0;
}

/*
* 运行时间16ms, 击败67.71% c++用户
* 消耗内存21.13M, 击败51.30% c++用户
*/
