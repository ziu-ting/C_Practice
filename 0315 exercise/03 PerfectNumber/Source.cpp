#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int x;//砞竚饼耞琌Ч计ぇタ俱计
	printf("叫块タ俱计:");
	scanf("%d", &x);

	int factor = 1;//factor++ 浪代ぇ计
	int sum = 0;//计羆
	while (factor<x)
	{
		if (x%factor == 0) {
			sum = sum + factor;//计羆
		}
		factor++;//眖1秨﹍碝т计
	}

	printf("计ぇ计羆:\t%d\n", sum);

	if (sum==x)
	{
		printf("计琌Ч计\n");
	}
	else
	{
		printf("硂ぃ琌Ч计\n");
	}

	system("pause");
}