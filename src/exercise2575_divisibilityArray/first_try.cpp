/*
给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。

word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：

如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。

示例1:
    输入：word = "998244353", m = 3
    输出：[1,1,0,0,0,1,1,0,0]
    解释：仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。

示例 2：
    输入：word = "1010", m = 10
    输出：[0,1,0,1]
    解释：仅有 2 个前缀可以被 10 整除："10" 和 "1010" 。


1 <= n <= 10^5
word.length == n
word 由数字 0 到 9 组成
1 <= m <= 10^9
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
    vector<int> divisibilityArray(string word, int m) {
        /*因为word的长度可以到10^5, 其所代表的最大数字超过了int可表示的情况, 所以不能简单累加前面的和*/
        /*若a mod b = c, 则10a mod b = 10c, 虽然10c可能还能继续取余, 但是它不可能超过10b, 由于b最大是10^9, 10b最大是10^10, int最大是2^31 - 1, 能够包含*/
        long long total_mod = 0;
        vector<int> result;

        for (int i = 0; i < word.length(); i++)
        {
            long long cur_mod = (total_mod * 10 + word[i] - '0') % m;
            if (cur_mod % m == 0) {
                result.emplace_back(1);
                total_mod = 0;
            }
            else {
                result.emplace_back(0);
                total_mod = cur_mod;
            }
        }

        return result;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间27ms, 击败97.33% c++用户
* 消耗内存26.99M, 击败8.00% c++用户
*/
