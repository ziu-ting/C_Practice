#include<stdio.h>
#include<stdlib.h>

//sum the number

//p.2-7 example

int main(void){

	int num1, num2;
	int	sum;

	printf("%s", "please input the first number:");
	scanf("%d", &num1);

	printf("%s", "please input the second number:");
	scanf("%d", &num2);

	sum = num1 + num2;//add num2 to num1

	printf("%s %d\n", "the sum is", sum);

}//end main