/************************************************************************/
/* 
*	编写一个函数来查找字符串数组中的最长公共前缀。
*	
*	如果不存在公共前缀，返回空字符串 ""。
*	
*	示例 1:
*	输入: ["flower","flow","flight"]
*	输出: "fl"
*	示例 2:
*	输入: ["dog","racecar","car"]
*	输出: ""
*	解释: 输入不存在公共前缀。

*	说明:
*	所有输入只包含小写字母 a-z 。
*/
/************************************************************************/

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const std::string longestCommonPrefix(const std::vector<std::string>& strs) 
{
	if (strs.size() < 1)
		return "";
	
	std::string shortestStr = strs[0];
	for (size_t i = 0; i < strs.size(); ++i)
	{
		if (shortestStr.length() > strs[i].length())
			shortestStr = strs[i];
	}

	std::string prefix = "";
	for (size_t i = 0; i < shortestStr.length(); ++i)
	{
		for (size_t j = 0; j < strs.size(); ++j)
		{
			if (strs[j][i] != shortestStr[i])
				return prefix;
		}

		prefix += shortestStr[i];
	}

	return prefix;
}

const std::string longestCommonPrefix1(const std::vector<std::string>& strs)
{
	if (strs.empty())
		return "";

	std::string prefix = strs[0];
	for(size_t i = 1; i < strs.size(); ++i)
		while (strs[i].find(prefix) == std::string::npos)
		{
			prefix = prefix.substr(0, prefix.length() - 1);
			if (prefix.empty())
				return "";
		}

	return prefix;
}

const std::string commonPrefix(const std::string& lhr, const std::string& rhr)
{
	size_t minCount = std::min(lhr.size(), rhr.size());
	for (size_t i = 0; minCount; ++i)
	{
		if (lhr[i] != rhr[i])
			return lhr.substr(0, i);
	}

	return lhr.substr(0, minCount);
}

const std::string longestCommonPrefix2(const std::vector<std::string>& strs, size_t l, size_t r)
{
	if (l == r)
	{
		return strs[l];
	}
	else
	{
		size_t mid = (l + r) / 2;
		const std::string lStr = longestCommonPrefix2(strs, l, mid);
		const std::string rStr = longestCommonPrefix2(strs, mid + 1, r);
		return commonPrefix(lStr, rStr);
	}
}

const std::string longestCommonPrefix2(const std::vector<std::string>& strs)
{
	if (strs.empty())
		return "";

	return longestCommonPrefix2(strs, 0, strs.size() - 1);
}

int main()
{
	std::cout << longestCommonPrefix2({ "flower","flow","flight" }) << std::endl;
	std::cout << longestCommonPrefix2({ "dog","racecar","car" }) << std::endl;
	std::cout << longestCommonPrefix2({  }) << std::endl;
	std::cout << longestCommonPrefix2({ "migrate" }) << std::endl;

	system("pause");
}
