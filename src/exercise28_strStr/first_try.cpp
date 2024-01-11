/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。


输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。


1 <= haystack.length, needle.length <= 104
haystack 和 needle 仅由小写英文字符组成

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_len = needle.length();
        int haystack_len = haystack.length();

        for (int i = 0; i < haystack_len; i++) {
            string substring = haystack.substr(i, needle_len);
            if (substring == needle)
                return i;
        }

        return -1;
    }
};

int main() {
    std::string haystack = "leetcode";
    std::string needle = "leeto";

    Solution solution;
    int k = solution.strStr(haystack, needle);

    std::cout << k << std::endl;

    return 0;
}


/*
* 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
* 内存消耗：6.06MB, 在所有 C++ 提交中击败了23.08%的用户
*/

