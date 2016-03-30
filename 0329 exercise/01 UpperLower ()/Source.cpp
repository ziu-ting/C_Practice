#include<stdio.h>
#include<stdlib.h>
#include"transfer.h"



int main(void) {
	char letter;
	printf("請輸入字母:");//建置一使用者可以輸入之字母
	scanf(" %c", &letter);
	char A = toUpperCase(letter);
	char a = toLowerCase(letter);
	printf(" %c 的大寫為 %c\n", letter,A );
	printf(" %c 的小寫為 %c\n", letter,a );


	system("pause");
}

