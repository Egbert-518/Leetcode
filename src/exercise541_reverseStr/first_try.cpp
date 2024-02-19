/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例1：
    输入：s = "abcdefg", k = 2
    输出："bacdfeg"

示例2:
    输入：s = "abcd", k = 2
    输出："bacd"

1 <= s.length <= 10^4
s 仅由小写英文组成
1 <= k <= 10^4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        /*s的length可以获得, 先除以2k得到商和余数, 对商值做遍历, 余数进行判断*/

        int div = s.length() / (2 * k);
        int mod = s.length() % (2 * k);

        for (int i = 0; i < div; i++)
        {
            int left = i * 2 * k, right = i * 2 * k + k - 1;    // [0, k), [2k, 3k)
            while (left <= right)
            {
                char tmp_str = s[left];
                s[left] = s[right];
                s[right] = tmp_str;
                left++;
                right--;
            }
        }

        // 处理最后的余数
        mod = mod > k ? k : mod;   // 统一变量处理, 取mod与k中较小的那个进行翻转, 满足mod > k时翻转k个, mod <= k 时全部翻转
        int left = div * 2 * k, right = div * 2 * k + mod - 1;
        while (left < right)
        {
            char tmp_str = s[left];
            s[left] = s[right];
            s[right] = tmp_str;
            left++;
            right--;
        }

        return s;
    }
};



int main() 
{

    return 0;
}

/*
* 运行时间4ms, 击败91.47％ c++用户
* 消耗内存7.48M, 击败55.06% c++用户
*/
