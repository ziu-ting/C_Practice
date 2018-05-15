#include<stdio.h>
#include<stdlib.h>

void change(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

//判斷是否重複
bool IsSwap(char *pszStr, int nBegin, int nEnd)
{
	for (int i = nBegin; i < nEnd; i++) {
		if (pszStr[i] == pszStr[nEnd]) {
			return false;
		}
		return true;
	}
}

void P(char *a, int startpoint, int m) {
	if (startpoint == m)
	{
	
		printf("%s\n",a);
		//return;
	}

	else
	{
		for (int i = startpoint; i < m; i++) {

			if (IsSwap(a, startpoint, i))
			{
				change(a + i, a + startpoint);
				P(a, startpoint + 1, m);
				change(a + i, a + startpoint);
			}

		}
	}
	
}

int main(void) {
	int x;//使使用者決定共要輸入幾個數字
	printf("請輸入欲排列幾個數：");
	scanf("%d", &x);

	while (x == 0)
	{
		printf("請輸入正整數!\n");
		printf("請輸入欲排列幾個數：");
		scanf("%d", &x);
	}

	char number[1000] = { 0 };
	for (int i = 0; i < x; i++)
	{
		printf("請輸入第%d個數之值：", i + 1);
		scanf(" %c", &number[i]);
		while (number[i] == 0)
		{
			printf("請輸入正整數!\n");
			printf("請輸入第%d個數之值：", i + 1);
			scanf("%d", &number[i]);
		}
	}

	P(number, 0, x);

}




