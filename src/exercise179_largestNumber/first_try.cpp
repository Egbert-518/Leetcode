/*
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。


示例1:
    输入：nums = [10,2]
    输出："210"

示例 2：
    输入：nums = [3,30,34,5,9]
    输出："9534330"


1 <= nums.length <= 100
0 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            nums_str[i] = std::to_string(nums[i]);
        }
        sort(nums_str.begin(), nums_str.end(), cmp);
        string result = nums_str[0];
        if (result == "0") {
            return result;   // 最大的是0, 不需要叠加返回了
        }
        for (int i = 1; i < nums_str.size(); i++)
        {
            result = result + nums_str[i];
        }
        return result;
    }

    static bool cmp(string a, string b) {
        return a + b > b + a;
    }
};


int main()
{


    return 0;
}

/*
* 运行时间7ms, 击败51.54% c++用户
* 消耗内存17.00M, 击败5.14% c++用户
*/
