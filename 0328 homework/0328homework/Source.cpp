#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("�п�J�@�ӤQ���i�줧�|�쥿���:");
	int num_1;//�ظm�i��J��������x
	scanf("%x", &num_1);//�N��J�ȳ]�w��16�i�� 
	if (num_1<65536)//�P�wx�O�_���|��� �Q���i��ffff���Q�i��Ȭ�65535
	{
		printf("x(�Q���i��\t�Q�i��):\n\t %x\t%d\n", num_1, num_1);//�Nx�L�X��16�i��Ƥ�10�i���
	}
	else
	{
		printf("�п�J���ĤQ���i�줧�|��ơC");
		return 0;//�Yx�W�L4��ƫh�פ�
	}

	printf("�п�J�t�@�ӤQ���i�줧�|�쥿���:");
	int num_2;//�ظm�i��J��������y
	scanf("%x", &num_2);
	if (num_2<65536)//�P�wx�O�_���|��� 
	{
		printf("y(�Q���i��\t�Q�i��):\n\t %x\t%d\n", num_2, num_2);//�Ny�L�X��16�i��Ƥ�10�i���
	}
	else
	{
		printf("�п�J���ĤQ���i�줧�|��ơC");
		return 0;//�Yx�W�L4��ƫh�פ�
	}

	char op_1;//�ظm�B�⤸��J
	printf("�п�J�B�⤸(+�B-�B*�B/):");
	scanf(" %c", &op_1);//note:%c����W�����~ �ݦ���>>>>�e�m�Ů�i����
	if (op_1 =='+')
	{
		printf("%d + %d = %d",num_1,num_2,num_1 + num_2);
	}
	else if (op_1 == '-')
	{
		printf("%d - %d = %d",num_1,num_2,num_1 - num_2);
	}
	else if (op_1 == '*')
	{
		printf("%d * %d = %d",num_1,num_2,num_1 * num_2);
	}
	else if (op_1 == '/')
	{
		printf("%d / %d = %.3f\t(���Ȧܤp���I��ĤT��))",num_1,num_2,num_1 / (double)num_2);//�ഫ���i��ܤp��
	}
	else
	{
		printf("�п�J���ĹB�⤸�C");
	}

	system("pause");
	return 0;
}