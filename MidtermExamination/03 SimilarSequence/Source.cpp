#include<stdio.h>
#include<stdlib.h>

void change(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

//�P�_�O�_����
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
	int x;//�ϨϥΪ̨M�w�@�n��J�X�ӼƦr
	printf("�п�J���ƦC�X�ӼơG");
	scanf("%d", &x);

	while (x == 0)
	{
		printf("�п�J�����!\n");
		printf("�п�J���ƦC�X�ӼơG");
		scanf("%d", &x);
	}

	char number[1000] = { 0 };
	for (int i = 0; i < x; i++)
	{
		printf("�п�J��%d�ӼƤ��ȡG", i + 1);
		scanf(" %c", &number[i]);
		while (number[i] == 0)
		{
			printf("�п�J�����!\n");
			printf("�п�J��%d�ӼƤ��ȡG", i + 1);
			scanf("%d", &number[i]);
		}
	}

	P(number, 0, x);

}




