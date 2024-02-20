/*
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

示例 1：
    输入: k = 3, n = 7
    输出: [[1,2,4]]
    解释:
    1 + 2 + 4 = 7
    没有其他符合的组合了。

示例 2：
    输入: k = 3, n = 9
    输出: [[1,2,6], [1,3,5], [2,3,4]]
    解释:
    1 + 2 + 6 = 9
    1 + 3 + 5 = 9
    2 + 3 + 4 = 9
    没有其他符合的组合了。

示例 3：
    输入: k = 4, n = 1
    输出: []
    解释: 不存在有效的组合。
    在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。

2 <= k <= 9
1 <= n <= 60
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        /*n是目标, k是可取的数字个数, 应该再设置一个可取数字的上限, 所以再构造一个函数*/
        return combinationSum(k, n, 9);
    }

    vector<vector<int>> combinationSum(int num_count, int target, int limit) {
        vector<vector<int>> sum_combinations;
        if (num_count == 1) {
            // 终止条件
            if (target <= limit) {
                // 可以实现
                vector<int> result = { target };
                sum_combinations.emplace_back(result);
                return sum_combinations;
            }
            else {
                // 不可以实现, 返回空数组
                return sum_combinations;
            }
        }

        for (int i = 1; i <= limit; i++)
        {
            if (target - i > 0) {
                // 剪枝, 如果target - i已经小于0, 则不需要再往下走了, 因为必不可能满足
                vector<vector<int>> cur_combination = combinationSum(num_count - 1, target - i, i - 1);
                if (cur_combination.empty()) {
                    continue;   // 来自底层的为空, 说明没找到合适的数字和
                }
                else {
                    for (vector<int> combination : cur_combination)
                    {
                        combination.emplace_back(i);
                        sum_combinations.emplace_back(combination);
                    }
                }
            }

        }

        return sum_combinations;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> combinations = solution.combinationSum3(4, 1);
    for (vector<int> combination : combinations)
    {
        for (int i = 0; i < combination.size(); i++)
        {
            std::cout << combination[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
* 运行时间3ms, 击败29.10% c++用户
* 消耗内存8.36M, 击败5.00% c++用户
*/
