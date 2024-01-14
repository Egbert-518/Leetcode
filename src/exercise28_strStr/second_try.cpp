/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：
    输入：haystack = "sadbutsad", needle = "sad"
    输出：0
    解释："sad" 在下标 0 和 6 处匹配。
    第一个匹配项的下标是 0 ，所以返回 0 。


1 <= haystack.length, needle.length <= 10^4
haystack 和 needle 仅由小写英文字符组成
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void getNext(int* next, const string& s) {
        // 根据needle创建前缀表(通过next数组实现)
        int j = -1;
        next[0] = j;

        for (int i = 1; i < s.length(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }

            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        /*最初是利用了substr方法, 但这种方法估计在考试的时候不给用, 或者面试的时候会问有没有别的方法*/
        /*如果采用每次暴力匹配的方式, 时间成本太高, 因为一旦不对, 就要从头的下一位再开始遍历, 时间复杂度o(mn)*/
        /*KMP利用前缀表, 记录了非匹配位置应该回到哪个地方再进行匹配, 只需要遍历一遍haystack和needle即可, 时间复杂度o(m + n)*/
        if (needle.length() == 0) {
            return 0;   // 空字符串直接返回0
        }

        int* next = new int[needle.length()];
        getNext(next, needle);

        int j = -1;
        for (int i = 0; i < haystack.length(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])   // 不匹配, 则查找前缀表
            {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;   // i++在循环里
            }
            if (j == needle.length() - 1) {   // 查找完毕, 该返回数值了
                return i - j;
            }
        }

        return -1;
    }
};


int main()
{

    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存6.61M, 击败24.73% c++用户
*/
