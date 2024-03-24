/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：
    如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

示例1:
    输入：s = "abc", t = "ahbgdc"
    输出：true

示例 2：
    输入：s = "axc", t = "ahbgdc"
    输出：false


0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*dp[j]表示t中前j个长度的子串包含s从前到后的最大长度*/
        if (s.length() == 0 && t.length() == 0) {
            return true;
        }
        if (s.length() == 0) {
            return true;
        }
        if (t.length() == 0) {
            return false;
        }

        vector<int> dp(t.length() + 1, 0);

        for (int i = 1; i <= t.length(); i++)
        {
            if (t[i - 1] == s[dp[i - 1]]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = dp[i - 1];
            }

            if (dp[i] == s.length()) {
                return true;
            }
        }

        return false;
    }
};


int main()
{
    Solution solution;
    solution.isSubsequence("rjufvjafbxnbgriwgokdgqdqewn", "mjmqqjrmzkvhxlyruonekhhofpzzslupzojfuoztvzmmqvmlhgqxehojfowtrinbatjujaxekbcydldglkbxsqbbnrkhfdnpfbuaktupfftiljwpgglkjqunvithzlzpgikixqeuimmtbiskemplcvljqgvlzvnqxgedxqnznddkiujwhdefziydtquoudzxstpjjitmiimbjfgfjikkjycwgnpdxpeppsturjwkgnifinccvqzwlbmgpdaodzptyrjjkbqmgdrftfbwgimsmjpknuqtijrsnwvtytqqvookinzmkkkrkgwafohflvuedssukjgipgmypakhlckvizmqvycvbxhlljzejcaijqnfgobuhuiahtmxfzoplmmjfxtggwwxliplntkfuxjcnzcqsaagahbbneugiocexcfpszzomumfqpaiydssmihdoewahoswhlnpctjmkyufsvjlrflfiktndubnymenlmpyrhjxfdcq");
    return 0;
}

/*
* 运行时间2ms, 击败47.33% c++用户
* 消耗内存7.54M, 击败24.35% c++用户
*/
