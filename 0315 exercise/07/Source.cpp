#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	int number = 0;
	srand(time(NULL));
	number = rand() % 99 + 1;//�تv�׷��K�X�A�d��0+1~99+1

	int min = 1, max = 100;//�w�q�d��W�U��
	for (int i = 1; i>0; i++)//�ؤ@�L���j��ϯ୫�Ʋq
	{
	
		printf("�סC���C�K�C�X\n��%d��\t�d��G%d ~ %d\n", i, min, max);
		int guess;
		scanf("%d", &guess);
		if (guess<number)//�Ҳq�Ʀr�p��׷��K�X�A��s�U��
		{
			min = guess;
		}
		else if (guess>number)//�Ҳq�Ʀr�j��׷��K�X�A��s�W��
		{
			max = guess;
		}
		else
		{
			break;//��Ҳq���Ʀr����׷��K�X�ɦ۰ʲ�X
		}
		
	}
	printf("�׷��K�X��%d�I�I�I�����z���I",number);
	system("pause");
}
//�W�U�ɭY��J���ŦX�A������
//�Hwhile�]�w�|���L�k�B�@
//�ݭץ�