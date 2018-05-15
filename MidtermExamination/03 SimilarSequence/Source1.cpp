//�h�����ƦC�����j��{
#include <stdio.h>

void Swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
//�bpszStr�r��}�C���A[nBegin,nEnd)���O�_���Ʀr�O�U�Ь�nEnd���Ʀr�۵�
bool IsSwap(char *pszStr, int nBegin, int nEnd)
{
	for (int i = nBegin; i < nEnd; i++)
		if (pszStr[i] == pszStr[nEnd])
			return false;
	return true;
}
//k��ܷ�e�����ĴX�Ӽ�,m��ܦ@���h�ּ�.
void AllRange(char *pszStr, int k, int m)
{
	if (k == m)
	{
		static int s_i = 1;
		printf("  ��%3d�ӱƦC\t%s\n", s_i++, pszStr);
	}
	else
	{
		for (int i = k; i < m; i++) //��i�ӼƤ��O�P�L�᭱���Ʀr�洫�N��o��s���ƦC
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
	int x;//�ϨϥΪ̨M�w�@�n��J�X�ӼƦr
	printf("�п�J���ƦC�X�ӼơG");
	scanf("%d", &x);
	char number[1000] = { 0 };
	for (int i = 0; i < x; i++)
	{
		printf("�п�J��%d�ӼƤ��ȡG", i + 1);
		scanf(" %c", &number[i]);
	}
	

	printf("%s�����ƦC�p�U:\n", number);
	AllRange(number, 0, x );
	return 0;
}