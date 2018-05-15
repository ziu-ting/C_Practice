#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int year;//ㄏノ块惠耞ぇだ
	printf("叫块:");
	scanf("%d", &year);

	if (year%4==0)
	{
		int quarter_year = year / 4;//盢计埃4坝﹚竡穝跑计
		if (quarter_year%1000==0)//计4000计ぃ琌秥
		{
			printf("ぃ琌秥\n");
		}
		else if (quarter_year%100==0)//计400计琌秥
		{
			printf("琌秥\n");
		}
		else if (quarter_year%25==0)//计100计ぃ琌秥
		{
			printf("ぃ琌秥\n");
		}
		else//计4计琌秥
		{
			printf("琌秥\n");
		}
	}
	
	else//计ぃ4计ぃ琌秥
	{
		printf("ぃ琌秥\n");
	}
}