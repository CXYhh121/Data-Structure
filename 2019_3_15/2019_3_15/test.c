#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//int main()
//{
//	float a[10] = { 0.0 };
//	int i;
//
//	for (i = 0; i < 3; i++)
//		scanf("%d\n", &a[i]);
//	for (i = 0; i < 10; ++i)
//		a[0] = a[0] + a[i];
//	printf("%f\n", a[0]);
//	return 0;
//}

#include<stdio.h>
#include <string.h>
//#include<assert.h>
int My_strlen(const char* str)
{
	int count = 0;
	//assert(str != NULL);
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}
int main()
{
	char* str = "abcdefgh";
	int ret = My_strlen(str);
	printf("%d\n", ret);
	return 0;
}
