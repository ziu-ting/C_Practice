#include<stdio.h>
#include<stdlib.h>

#define PleaseDontImputTheNumberLargeThan1000 1000

void change(int &a, int &b);
//void P(int a[], int startpoint, int maximum);
	//�����ѦҡGhttp://programming.im.ncnu.edu.tw/Chapter10.htm		�u�C�X��ư}�C���Ҧ��ƦC�v
void Permutation(int a[], int startpoint, int chooce_n, int maximum);


int main(void) {
	int m, n;
	int numberarray[PleaseDontImputTheNumberLargeThan1000] = { 0 };
	//����s���ϥΪ̿�J�ӧP�_�}�C�j�p�A�w���N�}�C�j�p�]��1000�A�Y�̦h�u�వ1000�����ƦC
	//���L��J�o��h�|��ܤ[�a...QWQQQ  �U�Ф�U�d��

	printf("=====�ƦC�զX	P�]m,n�^====\n\n");

	printf("�п�J�`��m�G");
	scanf("%d", &m);
	while (m <= 0)//����m�d�򬰥����
	{
		printf("�п�J���ļƦr�I\n");
		printf("�п�J�`��m�G");
		scanf("%d", &m);
	}
	printf("�䤤�A������ƦCn���G");
	scanf("%d", &n);
	while (n <= 0 || n > m)//����n���d�򬰥���ơA�B���i�H�j��m
	{
		printf("�п�J���ļƦr�I\n");
		printf("������ƦCn���G");
		scanf("%d", &n);
	}


	while (m<0)
	{
		printf("�п�J���ļƦr�I");
	}

	for (int i = 0; i < m; i++)
	{
		numberarray[i] = i + 1;
	}

	printf("=====�Y�N�L�XP�]%d,%d�^���Ҧ��ƦC���G=====\n\n", m, n);

	Permutation(numberarray, 0,  n, m);
	system("pause");
}


//�إߤ@�զX�����
//����������ƦC�A�^�����q��L�X

void  Permutation(int a[], int startpoint,  int chooce_n, int maximum) {
	if (startpoint == chooce_n)//�q�}�C���ݶ}�l����A��ƧǦ�chooce_n(=n)�ɡA�L�X���G
	{
			for (int i = 0;i < chooce_n;i++) {//�L�X���G�d��G���ޭ�0 ~ chooce_n - 1
			printf("%d  ", a[i]);
		}
		putchar('\n');
		return;
	}
	for (int i = startpoint; i < maximum; i++)
	{
		change(a[i], a[startpoint]);
		Permutation(a, startpoint + 1, chooce_n, maximum);
		change(a[i], a[startpoint]);
	}

}

//�إߤ@�i�����Ƥ����
void change(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//����������ǡG�ƦC�����
/*
a[]�G�w�w�ƦC���}�C
startpoint�G
	�C�����j���_�l���ޭ�(�Ĥ@�Ӱ��欰maximum�A�q�}�C���ݶi��ƦC
	�i��ƦC�զX�����a�J��
maximum�G
	���}�C�@maximum���@�ƦC
	C m��n�����p�U���a�Jn
*/
void P(int a[], int startpoint, int maximum) {
	if (startpoint==maximum)//���j����_�l�I�b�}�C�̫�A�L�X�}�C
	{
		for (int i = 0;i < maximum;i++) {
			printf("%d", a[i]);	
		}
		putchar('\n');//�C���L�X���n����
		return;
	}

	/*
	�洫�����ܷN��
	A	B	C	D	E
				�â���
			�â��@�@��
			�â���
		�â�		��
		�â�	��
		�â���
		ETC.
	*/
	for (int i = startpoint; i < maximum; i++)
	{
		change(a[i], a[startpoint]);
		P(a, startpoint + 1, maximum);//�ϰ}�C�ƧǱq�}�C���ݶ}�l���j�i��
		change(a[i], a[startpoint]);
	}
}