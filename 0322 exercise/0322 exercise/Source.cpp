#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {

	int dice_number = 0;//�w�q���Ӧ��Y�X�ƭ�
	int num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0, num_5 = 0, num_6 = 0;//��l�]�w��1~6���Ȭ�0
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		
		dice_number = rand() % 6 + 1;

		switch (dice_number)
		{
		case 1:
			num_1++;
			break;
		case 2:
			num_2++;
			break;
		case 3:
			num_3++;
			break;
		case 4:
			num_4++;
			break;
		case 5:
			num_5++;
			break;
		case 6:
			num_6++;
			break;

		default:
			break;
		}
	}
	printf("�Y��l�@�d�����A�@�X�{%d��1�I�A��X�{���v��%.2f\n", num_1, (float)num_1 / 1000);
	printf("�Y��l�@�d�����A�@�X�{%d��2�I�A��X�{���v��%.2f\n", num_2, (float)num_2 / 1000);
	printf("�Y��l�@�d�����A�@�X�{%d��3�I�A��X�{���v��%.2f\n", num_3, (float)num_3 / 1000);
	printf("�Y��l�@�d�����A�@�X�{%d��4�I�A��X�{���v��%.2f\n", num_4, (float)num_4 / 1000);
	printf("�Y��l�@�d�����A�@�X�{%d��5�I�A��X�{���v��%.2f\n", num_5, (float)num_5 / 1000);
	printf("�Y��l�@�d�����A�@�X�{%d��6�I�A��X�{���v��%.2f\n", num_6, (float)num_6 / 1000);
}