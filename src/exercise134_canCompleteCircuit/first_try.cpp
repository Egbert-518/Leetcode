/*
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

示例 1：
    输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    输出: 3
    解释:
    从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
    开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
    开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
    开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
    开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
    开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
    因此，3 可为起始索引。

示例 2:
    输入: gas = [2,3,4], cost = [3,4,3]
    输出: -1
    解释:
    你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
    我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
    开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
    开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
    你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
    因此，无论怎样，你都不可能绕环路行驶一周。


gas.length == n
cost.length == n
1 <= n <= 10^5
0 <= gas[i], cost[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*暴力遍历需要O(n^2), 考虑先做差得到净补给量, 然后从头开始遍历一遍, 如果求和<0, 则从下一个点开始计, 若在遍历完数组之前对某个点开始能累计遍历n次, 说明能开到, 否则开不到, O(3n)*/
        for (int i = 0; i < gas.size(); i++)
        {
            gas[i] = gas[i] - cost[i];
        }

        int cur_sum = 0;
        int cur_count = 0;
        for (int i = 0; i < 2 * gas.size(); i++)   // O(3n)
        {
            cur_sum = cur_sum + gas[i % gas.size()];    // 将gas首尾拼接, 通过取余访问
            if (cur_sum < 0) {
                cur_count = 0;
                cur_sum = 0;
            }
            else {
                cur_count++;
                if (cur_count == gas.size()) {
                    return i + 1 - cur_count;  // i表示从第i车站到第i+1车站, 最终落在i+1车站
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> gas = { 1, 2, 3, 4, 5 };
    vector<int> cost = { 3, 4, 5, 1, 2 };
    int result = solution.canCompleteCircuit(gas, cost);
    return 0;
}

/*
* 运行时间100ms, 击败93.69％ c++用户
* 消耗内存127.50M, 击败24.16% c++用户
*/
