#include<stdio.h>
#include<stdlib.h>
#include"transfer.h"



int main(void) {
	char letter;
	printf("�п�J�r��:");//�ظm�@�ϥΪ̥i�H��J���r��
	scanf(" %c", &letter);
	char A = toUpperCase(letter);
	char a = toLowerCase(letter);
	printf(" %c ���j�g�� %c\n", letter,A );
	printf(" %c ���p�g�� %c\n", letter,a );


	system("pause");
}

