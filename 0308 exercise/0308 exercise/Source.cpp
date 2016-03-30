#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("請輸入整數x之值:\t");
	int num_1;//建置可輸入之整數x
	scanf("%d", &num_1);

	printf("請輸入整數y之值:\t");
	int num_2;//建置可輸入之整數y
	scanf("%d", &num_2);

	//印出x與y之四則運算結果
	printf(" %d + %d = %d \n", num_1, num_2, num_1 + num_2);
	printf(" %d - %d = %d \n", num_1, num_2, num_1 - num_2);
	printf(" %d * %d = %d \n", num_1, num_2, num_1 * num_2);
	printf(" %d / %d = %.2f \n", num_1, num_2, num_1 / (float)num_2);//將除數轉換成float 以顯示小數點 並限制顯示小數點後兩位

	system("pause");
}