/************************************************************************/
/* 
	判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
	示例 1:
	输入: 121
	输出 : true
	示例 2 :
	输入 : -121
	输出 : false
	解释 : 从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
	示例 3 :
	输入 : 10
	输出 : false
	解释 : 从右向左读, 为 01 。因此它不是一个回文数。
	进阶 :
	你能不将整数转为字符串来解决这个问题吗？
*/
/************************************************************************/

#include "pch.h"
#include <iostream>
#include <string>
#include <queue>

const bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	int tmp = x;
	int result = 0;
	while (tmp != 0)
	{
		int pop = tmp % 10;
		tmp /= 10;

		if (result > INT_MAX / 10 || (INT_MAX / 10 == result && pop > 7))
			return false;

		if (result < INT_MIN / 10 || (INT_MIN / 10 == result && pop < -8))
			return false;

		result = result * 10 + pop;
	}

	return result == x;
}

const bool isPalindrome1(int x)
{
	if ((x < 0) || (0 == x % 10 && x != 0))
		return false;

	int halfRev = 0;
	while (x > halfRev)	// 反转x的一半
	{
		halfRev = halfRev * 10 + x % 10;
		x /= 10;
	}

	return halfRev == x || x == halfRev / 10;
}

int main()
{
	int x = 0;
	std::cin >> x;
    std::cout << (isPalindrome(x) ? "true" : "false") << std::endl; 
	std::cout << (isPalindrome1(x) ? "true" : "false") << std::endl;
	system("pause");

	return 0;
}
