/*
给你两个正整数：n 和 target 。

如果数组 nums 满足下述条件，则称其为 美丽数组 。
    nums.length == n.
    nums 由两两互不相同的正整数组成。
    在范围 [0, n-1] 内，不存在 两个 不同 下标 i 和 j ，使得 nums[i] + nums[j] == target 。
返回符合条件的美丽数组所可能具备的 最小 和，并对结果进行取模 109 + 7。

示例1:
    输入：n = 2, target = 3
    输出：4
    解释：nums = [1,3] 是美丽数组。
    - nums 的长度为 n = 2 。
    - nums 由两两互不相同的正整数组成。
    - 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
    可以证明 4 是符合条件的美丽数组所可能具备的最小和。

示例 2：
    输入：n = 3, target = 3
    输出：8
    解释：
    nums = [1,3,4] 是美丽数组。
    - nums 的长度为 n = 3 。
    - nums 由两两互不相同的正整数组成。
    - 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
    可以证明 8 是符合条件的美丽数组所可能具备的最小和。

示例 3：
    输入：n = 1, target = 1
    输出：1
    解释：nums = [1] 是美丽数组。

1 <= n <= 10^9
1 <= target <= 10^9
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
    int minimumPossibleSum(int n, int target) {
        int count = 0;
        int sum = 0;
        unordered_set<int> st;

        for (int i = 1; count < n; i++)
        {
            if (i >= target) {
                sum += i;
                count++;
            }
            else {
                if (st.find(i) == st.end()) {
                    sum += i;
                    count++;
                    st.insert(target - i);
                }
                else {
                    continue;
                }
            }
        }
        if (sum > 1000000000) {
            return (sum % 1000000000) + 7;
        }
        else {
            return sum;
        }
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 超过内存限制
* 官方题解为:
* class Solution {
    public:
        int minimumPossibleSum(int n, int target) {
            const int mod = 1e9 + 7;
            int m = target / 2;
            if (n <= m) {
                return (long long) (1 + n) * n / 2 % mod;
            }
            return ((long long) (1 + m) * m / 2 + 
                    ((long long) target + target + (n - m) - 1) * (n - m) / 2) % mod;
        }
    };
*/
