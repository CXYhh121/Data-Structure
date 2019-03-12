#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//反转整数
//class Solution {
//public:
//	int reverse(int x) {
//		int a = 0;
//		long ret = 0;
//		while (x != 0)
//		{
//			a = x % 10;
//			x = x / 10;
//			ret = ret * 10 + a;
//
//			if (ret < INT_MIN || ret > INT_MAX)
//				return 0;
//		}
//
//		return (int)ret;
//	}
//};
//
//int main()
//{
//	Solution s;
//	int ret = s.reverse(123);
//
//	printf("%d\n", ret);
//	return 0;
//}


//验证回文数
//class Solution {
//public:
//	int reverse(int x) {
//		int a = 0;
//		long ret = 0;
//		while (x != 0)
//		{
//			a = x % 10;
//			x = x / 10;
//			ret = ret * 10 + a;
//
//			if (ret < INT_MIN || ret > INT_MAX)
//				return 0;
//		}
//
//		return (int)ret;
//	}
//	bool isPalindrome(int x) {
//		if (x < 0)
//			return false;
//		int ret = reverse(x);
//
//		if (ret == x)
//			return true;
//		else
//			return false;
//	}
//};
//
//int main()
//{
//	Solution s;
//	printf("%d\n",s.isPalindrome(1234));
//	return 0;
//}

//罗马数字转整数
class Solution {
public:
	int romanToInt(string s) {
		int sum[50] = { 0 }, num = 0;
		for (size_t i = 0; i<s.length(); i++)
		{
			switch (s[i])
			{
			case 'I':sum[i] = 1; break;
			case 'V':sum[i] = 5; break;
			case 'X':sum[i] = 10; break;
			case 'L':sum[i] = 50; break;
			case 'C':sum[i] = 100; break;
			case 'D':sum[i] = 500; break;
			case 'M':sum[i] = 1000; break;
			}
			//若是后一个字符代表的数字是大于前一个的，就用后一个字符的值减去前一个得值
			//eg：IV，4就是等于 v(5) - I(1) = 4;
            if(i > 0&&sum[i] > sum[i-1]) 
                sum[i-1] =- sum[i-1];
        }
        for(size_t i = 0;i < s.length();i++) 
            num = num + sum[i];
        return num;
        
    }
};

int main()
{
	Solution s;
	char *str = "MDCL";
		int ret = s.romanToInt(str);

		printf("%d\n", ret);
	return 0;
}