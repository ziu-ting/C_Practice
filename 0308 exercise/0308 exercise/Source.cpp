#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("�п�J���x����:\t");
	int num_1;//�ظm�i��J�����x
	scanf("%d", &num_1);

	printf("�п�J���y����:\t");
	int num_2;//�ظm�i��J�����y
	scanf("%d", &num_2);

	//�L�Xx�Py���|�h�B�⵲�G
	printf(" %d + %d = %d \n", num_1, num_2, num_1 + num_2);
	printf(" %d - %d = %d \n", num_1, num_2, num_1 - num_2);
	printf(" %d * %d = %d \n", num_1, num_2, num_1 * num_2);
	printf(" %d / %d = %.2f \n", num_1, num_2, num_1 / (float)num_2);//�N�����ഫ��float �H��ܤp���I �í�����ܤp���I����

	system("pause");
}