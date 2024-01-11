/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

示例1:
    输入：n = 2
    输出：2
    解释：有两种方法可以爬到楼顶。
    1. 1 阶 + 1 阶
    2. 2 阶

1 <= n <= 45
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        /*思路, f(n)种类为前一级种类f(n - 1)跳一次到达 + 前二级种类f(n - 2)跳两级到达, 即f(n) = f(n - 1) + f(n - 2)*/
        /*f(n - 2)跳一级到n - 1位置, 会统计在f(n - 1)中, 因此不需要再加, 这个式子相当于通过某状态能一步跳到另一状态的递推*/
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};


int main()
{   
    Solution solution;

    int clib_nums = solution.climbStairs(3);
    std::cout << clib_nums << std::endl;

    return 0;
} 

/*
* 执行时间0ms, 击败100.00%c++用户
* 内存消耗6.18M, 击败66.56%c++用户
*/