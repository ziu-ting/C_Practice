#include<stdio.h>
#include<stdlib.h>

int NFactorial(int x) {//�p�ⶥ��
	
	int ans = 1;
	for (x; x>0; x--)//��(x)*(x-1)*....*1
	{
		ans *= x;
	}

	return ans;
}

int NPower(int n, int m) {//�p�����...........�]���X��QWQQQ
	
	double ans = n;
	for (m; m >=1; m--)
	{
		ans *= n;
	}
	return ans;
}

int NFibonacci(int x) {//�p��O���ƦC�A�B�λ��^���
	
	if (x==0)//F(0)=0
	{
		return 0;
	}
	else if (x==1)//F(1)=1
	{
		return 1;
	}
	else//F(x)�Ax>=2
	{
		return NFibonacci(x - 1) + NFibonacci(x - 2);
	}

}

int main(void) {
	printf("===�w��ϥΨ�ƭp���===\n\n���p�����p�⤧��Ƭ��G\n1\t����\n2\t���ƨ��\n3\t�O���ƦC\n\n�п�ܱ��D����ơG\t");

	int chooce;//�إߤ@�ܼƨϨϥΪ̿�ܩҭn�B�Τ����
	scanf("%d", &chooce);
	switch (chooce)//�̩ҿ�J���ȡA��ܶi�椧���
	{

	case 1://�i�涥���B��
		printf("�ҿ�ܤ���Ƭ�\t����\n\n");
		printf("�п�J���D����������\n�ܡI\t ��=");
		int x_1;
		scanf("%d", &x_1);
		printf("%d�I=%d", x_1, NFactorial(x_1));
		break;
	case 2://�i����ƹB��
		printf("�ҿ�ܤ���Ƭ�\t���ƨ��\n\n");
		printf("�п�J���D�����ƻP�����\n��^m\t(��,m)=");
		int n, m;
		scanf("(%d,%d)", &n, &m);
		printf("%d^%d=%d", n, m, NPower(n, m));
		break;
	case 3://�i��O���ƦC
		printf("�ҿ�ܤ���Ƭ�\t�O���ƦC\n\n");
		printf("�п�J���D�O���ƦC������\n�ԡ]n�^\tn=");
		int x_3;
		scanf("%d", &x_3);
		printf("F(%d)=%d", x_3, NFibonacci(x_3));
		break;
	default:
		break;
	}
	system("pause");
}

