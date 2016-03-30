#include<stdio.h>
#include<stdlib.h>

int main(void) {
	
	char name[15];//姓名為字串
	int bd_y,bd_m,bd_d;//將生日年月日分別設為整數變數
	float height, weight;//身高、體重為浮點數
	printf("請輸入您的姓名:\t");
	scanf(" %s", &name);
	printf("您好，%s，\n",name);
	printf("請輸入您的生日:(YYYY-MM-DD)\t");
	scanf("%d-%d-%d",&bd_y,&bd_m,&bd_d);
	printf("請輸入您的身高(cm):\t");
	scanf("%f", &height);
	printf("請輸入您的體重(kg):\t");
	scanf("%f", &weight);

	printf("\n\n=====%s您好，下列為您的基本資料=====\n",name);//分隔線
	printf("姓名:%s\n", name);
	printf("生日:%d年 %d月 %d日\n",bd_y,bd_m,bd_d);
	printf("身高:%.2f (cm)\n", height);
	printf("體重:%.2f (kg)\n", weight);

	double bmi;//計算BMI
	bmi = weight / height / height * 10000;

	printf("BMI值為:%f (kg/m^2)\n",bmi);

	system("pause");
}