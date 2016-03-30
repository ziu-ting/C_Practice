#include<stdio.h>
#include<stdlib.h>

int main(void) {
	printf("請輸入班級學生總人數:");
	int count;//設置班級總人數
	scanf("%d", &count);

	int sum = 0;//設置學生成績加總
	int i = 1;//i++ 限制迴圈執行次數
	while (i<=count)//使能依學生總人數決定輸入次數
	{
		printf("請輸入座號 %d學生之成績:",i);
		int score;
		scanf("%d", &score);

		sum = sum + score;//加總成績
		i++;
	}
	float average = sum / (float)count;//平均=總成績/總人數
	printf("全班總成績為:\t%.2f\n", average);

	system("pause");
}