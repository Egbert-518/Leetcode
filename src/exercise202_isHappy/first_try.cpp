/*
编写一个算法来判断一个数 n 是不是快乐数。


「快乐数」 定义为：
- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
- 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
- 如果这个过程 结果为 1，那么这个数就是快乐数。
- 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例1：
    输入：n = 19
    输出：true
    解释：
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:

    int getSum(int n) {
        int sum = 0;
        while (n != 0)
        {
            int mod = n % 10;
            sum += mod * mod;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        /*思路在于, 如果是非快乐数, 在运算过程中一定会出现重复的和, 可以通过哈希表来快速搜索是否存在重复的和, 若有, 结束循环return false, 否则直到求到1*/
        unordered_set<int> set;

        while (n != 1) 
        {
            n = getSum(n);
            if (set.find(n) != set.end()) {
                return false;
            }
            else {
                set.insert(n);
            }
        }
        return true;
    }
};


int main() 
{
    Solution solution;
    if (solution.isHappy(2)) {
        std::cout << "is happy " << std::endl;
    }
    else {
        std::cout << "not happy" << std::endl;
    }

    return 0;
}

/*
* 运行时间0ms, 击败100.00％ c++用户
* 消耗内存6.50M, 击败51.94% c++用户
*/
