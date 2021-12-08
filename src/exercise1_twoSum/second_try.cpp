#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> hash_map;   // 创建hash表, 搜索效率更高
		std::vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = hash_map.find(target - nums.at(i));   // 在hash表中查找有没有当前的元素值对应的target - item值, 如有, 则把这个元素和找到元素的下标返回
			if (it != hash_map.end())
			{
				result.emplace_back(i);
				result.emplace_back(it->second);
				return result;
			}
			hash_map[nums[i]] = i;
		}
		return result;
	}
};
