/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ostream& operator<<(ostream& os, vector<int> v)  //对左移运算符进行重载
{
    for (int i = 0; i < v.size(); i++)
        os << v[i] << " ";
    return os;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() < 3) {
            return results;
        }
        sort(nums.begin(), nums.end());   // 首先将nums按从小到大排列
        auto first = nums.begin();
        int curfirstMax = INT32_MIN;
        while (first != nums.end()) {
            if (*first > 0) {  // 最小的超过0, 提前终止
                return results;
            }
            else if (*first <= curfirstMax) {
                first++;
                continue;
            }
            else {
                curfirstMax = *first;
            }

            
            auto third = nums.end() - 1;
            int cursecondMax = INT32_MIN;  

            for (auto second = first + 1; second != nums.end(); second++) {
                if (*second <= cursecondMax) {   // 避免重复
                    continue;
                }
                else {
                    cursecondMax = *second;
                }
                int needInsert = 0 - *first - *second;
                while (*third > needInsert && third >= second) {   // 没找到
                    third--;
                }
                if (second >= third) {  // 越界
                    break;
                }
                if (*third == needInsert) {
                    vector<int> result{ *first, *second, *third };
                    results.emplace_back(result);
                }
            }
            first++;
        }
        return results;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{0, 1, 1};

    vector<vector<int>> results = solution.threeSum(nums);
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}

/*
* 执行用时：36 ms, 在所有 C++ 提交中击败了99.90%的用户
* 内存消耗：20.5MB, 在所有 C++ 提交中击败了21.27%的用户
* 通过测试用例：318 / 318
*/
