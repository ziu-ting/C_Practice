#include<stdio.h>
#include<stdlib.h>

//review插入排序法
void change(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sequence(int a[], int num) {
	for (int i = num-1; i >=0; i--)
	{
		while (a[num] < a[i]) {
			change(a[num], a[i]);
			num--;
		}
	}
}

int main(void) {
	int number[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		printf("請輸入第%d項:", i + 1);
		scanf("%d", &number[i]);

		sequence(number, i);
		while (i==9)
		{
			for (int j = 0;j < i;j++) {
				printf("%d\t", number[j]);
			}
			break;
		}
	}
}