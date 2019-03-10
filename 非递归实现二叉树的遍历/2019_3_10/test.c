#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h> 
//main()
//{
//	char c[2][5] = { "6938", "8254" }, *p[2];
//	int i, j, s = 0;
//	for (i = 0; i < 2; i++)
//		p[i] = c[i];
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; p[i][j] > 0; j += 2)
//			s = 10 * s + p[i][j] - '0 ';
//	}
//	   
//	printf("%d\n", s);
//}


#include <stdio.h>
int main()
{
	FILE *fp;
	int i, a[6] = { 1, 2, 3, 4, 5, 6 }, k;
	fp = fopen("data.dat", "w+b");
	for (i = 0; i<6; i++)
	{
		fseek(fp, 0L, 0);
		fwrite(&a[5-i], sizeof(int), 1, fp);
	}
	rewind(fp);
	fread(&k, sizeof(int), 1, fp);
	fclose(fp);
	printf("%d", k);
	return 0;
}