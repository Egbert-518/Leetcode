/*
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

示例1:
    输入：arr = [1,2,2,1,1,3]
    输出：true
    解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。

示例 2：
    输入：arr = [1,2]
    输出：false

示例 3：
    输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
    输出：true

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
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
    bool uniqueOccurrences(vector<int>& arr) {
        /*相当于自己建一个hash map*/
        int hash[2002] = { 0 };   // 总共是-1000到1000, 故2001个值
        for (int ele : arr)
        {
            hash[ele + 1000]++;
        }
        bool fre[2002] = { false };
        for (int i = 0; i < 2002; i++)
        {
            if (hash[i]) {
                if (!fre[hash[i]]) {
                    fre[hash[i]] = true;    // 这个频率没有被访问过, 则设置为访问
                }
                else {
                    return false;   // 如果之前已经有被访问, 则说明有相同的
                }
            }
        }

        return true;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间7ms, 击败16.01% c++用户
* 消耗内存11.41M, 击败5.02% c++用户
*/
