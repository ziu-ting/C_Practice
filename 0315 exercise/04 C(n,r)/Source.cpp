#include<stdio.h>
#include<stdlib.h>

int main(void) {
	//C��n��r
	printf("C(n,r) = n!/(r!*(n-r)!)\n");
	
	printf("�п�J�䤤��n��:");//�w�q�`��n
	int n;
	scanf("%d", &n);

	printf("�п�J�䤤��r��:");//�w�q�����ƶqr
	int r;
	scanf("%d", &r);

	//C(n,r)=n!/(r!*(n-r)!)

	//�]�m�T�ܼƤ��O��n!�Br!�B(n-r)!
	int sum_1 = 1;
	int	sum_2 = 1;
	int	sum_3 = 1;
	//�]�m�T�j��H���osum_1�Bsum_2�Bsum_3

	for (int i = 1; i <= n; i++)//n!
	{
		sum_1 = sum_1*i;
	}
	printf("%d! = %d\n", n, sum_1);

	for (int i = 1; i <= r; i++)//r!
	{
		sum_2 = sum_2*i;
	}
	printf("%d! = %d\n", r, sum_2);

	for (int i = 1; i <= n-r; i++)//(n-r)!
	{
		sum_3 = sum_3*i;
	}
	printf("%d! = %d\n", n-r, sum_3);

	double vales = sum_1 / sum_2 / (float)sum_3;
	printf("C(%d,%d) = %.2f\n", n, r, vales);

	system("pause");
	return 0;
}