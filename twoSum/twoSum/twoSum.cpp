////////////////////////////////////////////////////////
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
// 
// 示例 :
// 
// 给定 nums = [2, 7, 11, 15], target = 9
// 
// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回[0, 1]
///////////////////////////////////////////////////////

#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, const int target)
{
	std::unordered_map<int, int> hashMap{};
	std::vector<int> result(2, -1);
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (hashMap.count(target - nums[i]) > 0)
		{
			result[0] = hashMap[target - nums[i]];
			result[1] = i;
			break;
		}
		hashMap[nums[i]] = i;	// 构建hash表，方便索引
	}

	return result;
}

int main()
{
	std::vector<int> result = twoSum(std::vector<int>{2, 7, 11, 15}, 9);
	for (const auto ele : result)
	{
		std::cout << ele << std::endl;
	}

	return 0;
}
