#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dicefunction(char sum) {
	if (sum>=11&&sum<=18)
	{
		return 1;
	}
	else if (sum==9||sum==10)
	{
		return 2;
	}
	else if (sum<=8&&sum>=1)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int main(void) {
	
	char Dare;//��j���p
	int Own_money = 15;//�֦��`�w�X
	int Use_money = 0;//��`���B
	int End_money = 0;//�@���������Ĺ�o���B

	printf("=======�C���W�h=======\nB�G\t�j�G11~18\t�߲v�G2\nM�G\t���G09~10\t�߲v�G10\nS�G\t�p�G01~08\t�߲v�G2\nE�G\tEsc�G�פ�C��\n\n");
	printf("=======�C���}�l=======\n");

	srand(time(NULL));

	while (Own_money>0)
	{
		printf("�ثe�֦����B��\t%d\n", Own_money);
		printf("�п�J��`���B�G");
		scanf("%d", &Use_money);
		Own_money -= Use_money;//��s�`�w�X�����w�X��h��`���B

		printf("�п�J�]B/M/S/E�^�G");
		scanf(" %c", &Dare);

		int DiceSum = 0;//��l�]�w�T����l���Ȭ�0
		DiceSum += rand() % 6 + 1;
		DiceSum += rand() % 6 + 1;
		DiceSum += rand() % 6 + 1;

		if (Dare == 66 || Dare == 98 || Dare == 77 || Dare == 109 || Dare == 83 || Dare == 115 || Dare == 69 || Dare == 101)
		{
			switch (Dare)
			{
			case 66:
			case 98:
				if (DiceSum >= 11 && DiceSum <= 18)//�Y�뵲�G���j
				{
					End_money = Use_money * 2;
				}
				else
				{
					End_money = 0;
				}
				break;
			case 77:
			case 109:
				if (DiceSum == 9 || DiceSum == 10)//�Y�뵲�G���j
				{
					End_money = Use_money * 10;
				}
				else
				{
					End_money = 0;
				}
				break;
			case 83:
			case 115:
				if (DiceSum <= 8 && DiceSum >= 1)//�Y�뵲�G���j
				{
					End_money = Use_money * 2;
				}
				else
				{
					End_money = 0;
				}
				break;
			case 69:
			case 101:
				return 0;
				break;
			default:
				break;
			}
			printf("�Y�뵲�G��\t%d\n", DiceSum);
			Own_money = Own_money + End_money;
		}
		else
		{
			printf("�п�J���Ķ���\n");
			return 0;
		}
	}
	system("pause");

}