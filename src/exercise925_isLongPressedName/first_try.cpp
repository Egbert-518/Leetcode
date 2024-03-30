/*
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

示例1:
    输入：name = "alex", typed = "aaleex"
    输出：true
    解释：'alex' 中的 'a' 和 'e' 被长按。

示例 2：
    输入：name = "saeed", typed = "ssaaedd"
    输出：false
    解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。

1 <= name.length, typed.length <= 1000
name 和 typed 的字符都是小写字母
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
    bool isLongPressedName(string name, string typed) {
        int name_ptr = 0, typed_ptr = 0;
        int cur_count = 0;
        char cur_ch = name[0];
        while (name_ptr < name.length())
        {
            if (name[name_ptr] == cur_ch) {
                cur_count++;
                name_ptr++;
            }
            else {
                // 根据cur_count, 在typed中数
                int temp_count = 0;
                while (typed_ptr < typed.size() && typed[typed_ptr] == cur_ch)
                {
                    typed_ptr++;
                    temp_count++;
                }
                if (temp_count < cur_count) {
                    return false;
                }
                cur_count = 0;
                cur_ch = name[name_ptr];  // 这里name_ptr不增加, 因为当前的字符还未被统计
            }
        }
        // name中最后一个字符不会被判断
        int temp_count = 0;
        while (typed_ptr < typed.size() && typed[typed_ptr] == cur_ch)
        {
            typed_ptr++;
            temp_count++;
        }
        if (temp_count < cur_count || typed_ptr < typed.size()) {
            return false;
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
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存7.46M, 击败15.88% c++用户
*/
