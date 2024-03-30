/*
平衡字符串 中，'L' 和 'R' 字符的数量是相同的。

给你一个平衡字符串 s，请你将它分割成尽可能多的子字符串，并满足：

每个子字符串都是平衡字符串。
返回可以通过分割得到的平衡字符串的 最大数量 。

示例1:
    输入：s = "RLRRLLRLRL"
    输出：4
    解释：s 可以分割为 "RL"、"RRLL"、"RL"、"RL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。

示例 2：
    输入：s = "RLRRRLLRLL"
    输出：2
    解释：s 可以分割为 "RL"、"RRRLLRLL"，每个子字符串中都包含相同数量的 'L' 和 'R' 。
    注意，s 无法分割为 "RL"、"RR"、"RL"、"LR"、"LL" 因为第 2 个和第 5 个子字符串不是平衡字符串。

示例 3：
    输入：s = "LLLLRRRR"
    输出：1
    解释：s 只能保持原样 "LLLLRRRR" 。

2 <= s.length <= 1000
s[i] = 'L' 或 'R'
s 是一个 平衡 字符串
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
    int balancedStringSplit(string s) {
        /*s本身是一个平衡字符串, 若能分为两部分, 当前半部分为平衡子串时, 后半部分一定也为平衡字串*/
        /*所以若舍弃前面的一部分, 从中间找起, 肯定不划算, 故可以用贪心*/
        int r_num = 0, l_num = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'L') {
                l_num++;
            }
            else {
                r_num++;
            }
            if (l_num > 0 && r_num > 0 && l_num == r_num) {
                count++;
                l_num = 0;
                r_num = 0;
            }
        }
        return count;
    }
};


int main()
{
    Solution solution;
    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存7.23M, 击败25.20% c++用户
*/
