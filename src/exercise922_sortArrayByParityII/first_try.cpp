/*
给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。

对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。

你可以返回 任何满足上述条件的数组作为答案 。

示例1:
    输入：nums = [4,2,5,7]
    输出：[4,5,2,7]
    解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。

示例 2：
    输入：nums = [2,3]
    输出：[2,3]

2 <= nums.length <= 2 * 10^4
nums.length 是偶数
nums 中一半是偶数
0 <= nums[i] <= 1000
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
    vector<int> sortArrayByParityII(vector<int>& nums) {
        /*就是要让0, 2, 4...下标处为偶数, 1, 3, 5...处为奇数*/
        vector<int> results(nums.size(), 0);
        int cur_odd = 1, cur_even = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0) {
                results[cur_even] = nums[i];
                cur_even += 2;
            }
            else {
                results[cur_odd] = nums[i];
                cur_odd += 2;
            }
        }
        return results;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间14ms, 击败73.82% c++用户
* 消耗内存23.38M, 击败10.60% c++用户
*/
