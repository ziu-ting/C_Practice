#include<stdio.h>
#include<stdlib.h>

#define length 10

//�洫���ܼƤ���m
void change(int &m, int &n) {
	int temp;
	temp = m;
	m = n;
	n = temp;
}

//�˴��O�_�ɾ��Ƨ�
void sequence(int a[], int n) {//�}�C��a,��ɳ̰�����n
	
	for (int i = n-1; i>=0 ; i--)
	{
		while (a[n] < a[i])
		{
			change(a[n], a[i]);
			n--;//���ˬd���ƦV�e���ܤp��ᶵ   ���n!!!
		}
	}
	
}

int main(void) {
	/*
	//���ը禡change()�O�_�i����
	int x = 1;
	int y = 2;
	change(x,y);
	printf("%d,%d", x, y);
	*/

	int a[length] = { 0 };//��l�]�w�}�C���׬�length=10�A�B�U����l������0
	printf("���ƧǤ@���׬�%d���}�C\n", length);

	for (int i = 0; i < length; i++)
	{
		printf("�п�J��%d������\t",i);

		scanf("%d", &a[i]);//��J���}�C��i������	
		sequence(a, i);//�ƦC�}�C

		while (i==length-1)//���J�����ɡA�L�X�}�C
		{
			printf("���}�C�`����%d�A��ɾ��ƧǬ��G\n",length);
			for (int j = 0; j <= i; j++)
			{
				printf("%d\t", a[j]);
			}
			break;
		}
		
	}
	system("pause");
}