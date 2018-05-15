//去重全排列的遞迴實現
#include <stdio.h>

void Swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
//在pszStr字串陣列中，[nBegin,nEnd)中是否有數字与下標為nEnd的數字相等
bool IsSwap(char *pszStr, int nBegin, int nEnd)
{
	for (int i = nBegin; i < nEnd; i++)
		if (pszStr[i] == pszStr[nEnd])
			return false;
	return true;
}
//k表示當前選取到第幾個數,m表示共有多少數.
void AllRange(char *pszStr, int k, int m)
{
	if (k == m)
	{
		static int s_i = 1;
		printf("  第%3d個排列\t%s\n", s_i++, pszStr);
	}
	else
	{
		for (int i = k; i < m; i++) //第i個數分別與他後面的數字交換就能得到新的排列
		{                             
			if (IsSwap(pszStr, k, i))
			{
				Swap(pszStr + k, pszStr + i);
				AllRange(pszStr, k + 1, m);
				Swap(pszStr + k, pszStr + i);
			}
		}
	}
}

int main()
{
	int x;//使使用者決定共要輸入幾個數字
	printf("請輸入欲排列幾個數：");
	scanf("%d", &x);
	char number[1000] = { 0 };
	for (int i = 0; i < x; i++)
	{
		printf("請輸入第%d個數之值：", i + 1);
		scanf(" %c", &number[i]);
	}
	

	printf("%s的全排列如下:\n", number);
	AllRange(number, 0, x );
	return 0;
}