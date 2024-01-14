/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

示例 1：
    输入：s = "the sky is blue"
    输出："blue is sky the"

示例 2：
    输入：s = "  hello world  "
    输出："world hello"
    解释：反转后的字符串中不能存在前导空格和尾随空格。

示例 3：
    输入：s = "a good   example"
    输出："example good a"
    解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。

1 <= s.length <= 10^4
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        /*思路是, 从尾部开始遍历, 到非空字符时记录位置, 直到到空字符, 记录位置, 将字符串添加到新字符串上, 对于非第一次添加的, 需要加以空格*/
        int right_idx = s.length() - 1, left_idx = 0;   // 防止字符串头没有空格导致的第一个丢失
        bool begin_str = false, first_entry = true;
        string reverse_words;

        for (int i = s.length() - 1; i>=0; i--)
        {
            if (!begin_str && s[i] != ' ') {
                begin_str = true;
                right_idx = i;
            }
            else if (begin_str && s[i] == ' ') {
                begin_str = false;
                left_idx = i + 1;
                // 开始添加字符串
                if (first_entry) {
                    first_entry = false;
                    reverse_words = reverse_words + s.substr(left_idx, right_idx - left_idx + 1);
                }
                else {
                    reverse_words = reverse_words + " " + s.substr(left_idx, right_idx - left_idx + 1);
                }   
            }
        }

        if (begin_str && s[0] != ' ') {
            if (first_entry) {
                reverse_words = reverse_words + s.substr(0, right_idx + 1);
            }
            else {
                reverse_words = reverse_words + " " + s.substr(0, right_idx + 1);
            }
        }

        return reverse_words;
    }
};


int main() 
{
    Solution solution;
    string s = "a good   example";
    string reverse_s = solution.reverseWords(s);
    std::cout << reverse_s << std::endl;

    return 0;
}

/*
* 运行时间16ms, 击败8.01％ c++用户
* 消耗内存45.72M, 击败5.00% c++用户
*/
