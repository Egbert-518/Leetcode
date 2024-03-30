/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例1:
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
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] != 0) {
                i++;
            }
            else {
                for (int k = i + 1; k <= j; k++)
                {
                    nums[k - 1] = nums[k];
                }
                nums[j] = 0;
                j--;
            }
        }
    }

    void moveZeroesFast(vector<int>& nums) {
        // 真正的双指针法
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        // 将slowIndex之后的冗余元素赋值为0
        for (int i = slowIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间152ms, 击败7.03% c++用户
* 消耗内存21.21M, 击败8.29% c++用户
*/
