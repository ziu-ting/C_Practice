#include<stdio.h>
#include<stdlib.h>

int main(void) {
	
	char name[15];//�m�W���r��
	int bd_y,bd_m,bd_d;//�N�ͤ�~�����O�]������ܼ�
	float height, weight;//�����B�魫���B�I��
	printf("�п�J�z���m�W:\t");
	scanf(" %s", &name);
	printf("�z�n�A%s�A\n",name);
	printf("�п�J�z���ͤ�:(YYYY-MM-DD)\t");
	scanf("%d-%d-%d",&bd_y,&bd_m,&bd_d);
	printf("�п�J�z������(cm):\t");
	scanf("%f", &height);
	printf("�п�J�z���魫(kg):\t");
	scanf("%f", &weight);

	printf("\n\n=====%s�z�n�A�U�C���z���򥻸��=====\n",name);//���j�u
	printf("�m�W:%s\n", name);
	printf("�ͤ�:%d�~ %d�� %d��\n",bd_y,bd_m,bd_d);
	printf("����:%.2f (cm)\n", height);
	printf("�魫:%.2f (kg)\n", weight);

	double bmi;//�p��BMI
	bmi = weight / height / height * 10000;

	printf("BMI�Ȭ�:%f (kg/m^2)\n",bmi);

	system("pause");
}