/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

示例 1：
    输入：n = 4, k = 2
    输出：
    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]

示例 2：
    输入：n = 1, k = 1
    输出：[[1]]

1 <= n <= 20
1 <= k <= n
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /*回溯, 从当前元素中选一个, 再从剩余n - 1个元素中选k - 1个, 终止条件是选0个*/
        // 就这道题而言, 返回值与顺序无关, 即[1, 2]和[2, 1]是一样的, 只能返回一个, 因此当某个元素决定了后, 必须从小于它(或大于它的地方找)
        vector<vector<int>> all_nums;

        if (k == n) {
            vector<int> last_nums;
            for (int j = 1; j <= n; j++)
            {
                last_nums.emplace_back(j);
            }
            all_nums.emplace_back(last_nums);
            return all_nums;
        }

        // 只需要选一个, 从剩余的各选一遍
        if (k == 1) {
            for (int t = 1; t <= n; t++)
            {
                vector<int> last_nums = { t };
                all_nums.emplace_back(last_nums);
            }
            return all_nums;
        }

        for (int i = 1; i <= n; i++)
        {
            if (i >= k) {   // 确保集合内数字数量满足需要数字的数量
                vector<vector<int>> nums = combine(i - 1, k - 1);   // 从比当前值小的集合中再找k - 1个值
                for (vector<int> num : nums)
                {
                    num.push_back(i);
                    all_nums.push_back(num);
                }
            }
        }

        return all_nums;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> nums = solution.combine(4, 2);
    for (vector<int> num : nums)
    {
        for (int element : num)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
* 运行时间1146ms, 击败5.17% c++用户
* 消耗内存497.62M, 击败4.99% c++用户
*/
